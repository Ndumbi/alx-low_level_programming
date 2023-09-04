#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
#include <string.h>

void display_elf_info(Elf64_Ehdr *header);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
        return 98;
    }

    int fd = open(argv[1], O_RDONLY);

    if (fd == -1)
    {
        perror("Error opening file");
        return 98;
    }

    Elf64_Ehdr header;
    ssize_t n = read(fd, &header, sizeof(Elf64_Ehdr));

    if (n == -1)
    {
        perror("Error reading file");
        close(fd);
        return 98;
    }

    if (n != sizeof(Elf64_Ehdr) || memcmp(header.e_ident, ELFMAG, SELFMAG) != 0)
    {
        fprintf(stderr, "Error: Not an ELF file\n");
        close(fd);
        return 98;
    }

    display_elf_info(&header);

    close(fd);
    return 0;
}

void display_elf_info(Elf64_Ehdr *header)
{
    printf("ELF Header:\n");
    printf(" Magic: ");
    for (int i = 0; i < EI_NIDENT; i++)
        printf("%02x ", header->e_ident[i]);
    printf("\n");

    printf(" Class: ");
    if (header->e_ident[EI_CLASS] == ELFCLASS32)
        printf("ELF32\n");
    else if (header->e_ident[EI_CLASS] == ELFCLASS64)
        printf("ELF64\n");
    else
        printf("Invalid class\n");

    printf(" Data: ");
    if (header->e_ident[EI_DATA] == ELFDATA2LSB)
        printf("2's complement, little endian\n");
    else if (header->e_ident[EI_DATA] == ELFDATA2MSB)
        printf("2's complement, big endian\n");
    else
        printf("Invalid data encoding\n");

    printf(" Version: %d (current)\n", header->e_ident[EI_VERSION]);

    printf(" OS/ABI: ");
    switch (header->e_ident[EI_OSABI])
    {
    case ELFOSABI_SYSV:
        printf("UNIX - System V\n");
        break;
    case ELFOSABI_HPUX:
        printf("UNIX - HP-UX\n");
        break;
    case ELFOSABI_NETBSD:
        printf("UNIX - NetBSD\n");
        break;
    case ELFOSABI_LINUX:
        printf("UNIX - Linux\n");
        break;
    case ELFOSABI_SOLARIS:
        printf("UNIX - Solaris\n");
        break;
    case ELFOSABI_IRIX:
        printf("UNIX - IRIX\n");
        break;
    case ELFOSABI_FREEBSD:
        printf("UNIX - FreeBSD\n");
        break;
    case ELFOSABI_TRU64:
        printf("UNIX - TRU64\n");
        break;
    default:
        printf("Unknown\n");
        break;
    }

    printf(" ABI Version: %d\n", header->e_ident[EI_ABIVERSION]);

    printf(" Type: ");
    switch (header->e_type)
    {
    case ET_NONE:
        printf("NONE (None)\n");
        break;
    case ET_REL:
        printf("REL (Relocatable file)\n");
        break;
    case ET_EXEC:
        printf("EXEC (Executable file)\n");
        break;
    case ET_DYN:
        printf("DYN (Shared object file)\n");
        break;
    case ET_CORE:
        printf("CORE (Core file)\n");
        break;
    default:
        printf("Unknown\n");
        break;
    }

    printf(" Entry point address: %#lx\n", (unsigned long)header->e_entry);
}
