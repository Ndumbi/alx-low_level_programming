#include <elf.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_info(Elf64_Ehdr *header);
void close_elf(int elf);

void check_elf(unsigned char *e_ident)
{
    for (int index = 0; index < 4; index++)
    {
        if (e_ident[index] != ELFMAG[index])
        {
            fprintf(stderr, "Error: Not an ELF file\n");
            exit(98);
        }
    }
}

void print_magic(unsigned char *e_ident)
{
    printf(" Magic: ");

    for (int index = 0; index < EI_NIDENT; index++)
    {
        printf("%02x", e_ident[index]);

        if (index == EI_NIDENT - 1)
            printf("\n");
        else
            printf(" ");
    }
}

void print_info(Elf64_Ehdr *header)
{
    printf("ELF Header:\n");
    print_magic(header->e_ident);
    printf(" Class: %s\n", header->e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64");
    printf(" Data: %s\n", header->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "2's complement, big endian");
    printf(" Version: %d%s\n", header->e_ident[EI_VERSION], (header->e_ident[EI_VERSION] == EV_CURRENT) ? " (current)" : "");
    printf(" OS/ABI: ");

    switch (header->e_ident[EI_OSABI])
    {
    case ELFOSABI_NONE:
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
    case ELFOSABI_ARM:
        printf("ARM\n");
        break;
    case ELFOSABI_STANDALONE:
        printf("Standalone App\n");
        break;
    default:
        printf("<unknown: %x>\n", header->e_ident[EI_OSABI]);
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
        printf("<unknown: %x>\n", header->e_type);
    }

    printf(" Entry point address: %#lx\n", (unsigned long)header->e_entry);
}

void close_elf(int elf)
{
    if (close(elf) == -1)
    {
        fprintf(stderr, "Error: Can't close fd %d\n", elf);
        exit(98);
    }
}

int main(int argc, char *argv[])
{
    int fd;
    ssize_t n;
    Elf64_Ehdr header;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <ELF file>\n", argv[0]);
        return 1;
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return 98;
    }

    n = read(fd, &header, sizeof(Elf64_Ehdr));
    if (n == -1)
    {
        perror("Error reading file");
        close_elf(fd);
        return 98;
    }
    else if (n != sizeof(Elf64_Ehdr))
    {
        fprintf(stderr, "Error: Incomplete header read\n");
        close_elf(fd);
        return 98;
    }

    check_elf(header.e_ident);
    print_info(&header);

    close_elf(fd);
    return 0;
}
