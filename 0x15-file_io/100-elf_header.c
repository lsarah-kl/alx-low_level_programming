#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <elf.h>

void check_elf(unsigned char *e_ident);

void print_magic(unsigned char *e_ident);

void print_class(unsigned char *e_ident);

void print_data(unsigned char *e_ident);

void print_version(unsigned char *e_ident);

void print_osabi(unsigned char *e_ident);

void print_abi(unsigned char *e_ident);

void print_type(unsigned int e_type, unsigned char *e_ident);

void print_entry(unsigned long int e_entry, unsigned char *e_ident);

void close_elf(int elf);

/**
 * main - Entry point
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 *
 * Return: 0 if success, 98 if error.
 */
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(98);
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        fprintf(stderr, "Error: Can't read file %s\n", argv[1]);
        exit(98);
    }

    Elf64_Ehdr header;
    if (read(fd, &header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr))
    {
        close_elf(fd);
        fprintf(stderr, "Error: Unable to read file %s\n", argv[1]);
        exit(98);
    }

    check_elf(header.e_ident);
    printf("ELF Header:\n");
    print_magic(header.e_ident);
    print_class(header.e_ident);
    print_data(header.e_ident);
    print_version(header.e_ident);
    print_osabi(header.e_ident);
    print_abi(header.e_ident);
    print_type(header.e_type, header.e_ident);
    print_entry(header.e_entry, header.e_ident);

    close_elf(fd);
    return 0;
}

/**
 * check_elf - function that checks if the file is in ELF format.
 * @e_ident: Pointer to the ELF identification 
 *
 * If the file is not in ELF format, the function exits the program.
 */
void check_elf(unsigned char *e_ident)
{
    if (e_ident[EI_MAG0] != ELFMAG0 || e_ident[EI_MAG1] != ELFMAG1 ||
        e_ident[EI_MAG2] != ELFMAG2 || e_ident[EI_MAG3] != ELFMAG3)
    {
        fprintf(stderr, "Error: Not an ELF file\n");
        exit(98);
    }
}

void print_magic(unsigned char *e_ident)
{
    printf("  Magic:   ");
    for (int i = 0; i < EI_NIDENT; i++)
        printf("%02x ", e_ident[i]);
    printf("\n");
}

/**
 * print_class - Prints the ELF class (32-bit or 64-bit).
 * @e_ident: Pointer to the ELF identification bytes.
 *
 * The ELF class tells whether the file is 32-bit or 64-bit.
 */
void print_class(unsigned char *e_ident)
{
    printf("  Class:                             ");
    switch (e_ident[EI_CLASS])
    {
        case ELFCLASS32:
            printf("ELF32\n");
            break;
        case ELFCLASS64:
            printf("ELF64\n");
            break;
        default:
            printf("<unknown: %x>\n", e_ident[EI_CLASS]);
    }
}

void print_data(unsigned char *e_ident)
{
    printf("  Data:                              ");
    switch (e_ident[EI_DATA])
    {
        case ELFDATA2LSB:
            printf("2's complement, little endian\n");
            break;
        case ELFDATA2MSB:
            printf("2's complement, big endian\n");
            break;
        default:
            printf("<unknown: %x>\n", e_ident[EI_DATA]);
    }
}

/**
 * print_version - Prints the ELF version.
 * @e_ident: Pointer to the ELF identification bytes.
 *
 * The ELF version specifies the version of the ELF specification.
 */
void print_version(unsigned char *e_ident)
{
    printf("  Version:                           ");
    switch (e_ident[EI_VERSION])
    {
        case EV_CURRENT:
            printf("1 (current)\n");
            break;
        default:
            printf("<unknown: %x>\n", e_ident[EI_VERSION]);
    }
}

/**
 * print_osabi - Prints the operating system and ABI.
 * @e_ident: Pointer to the ELF identification bytes.
 *
 * The operating system and ABI specify the target operating system and ABI.
 */
void print_osabi(unsigned char *e_ident)
{
    printf("  OS/ABI:                            ");
    switch (e_ident[EI_OSABI])
    {
        case ELFOSABI_NONE:
            printf("UNIX - System V\n");
            break;
        case ELFOSABI_SYSV:
            printf("UNIX - System V\n");
            break;
        case ELFOSABI_HPUX:
            printf("HP-UX\n");
            break;
        case ELFOSABI_NETBSD:
            printf("NetBSD\n");
            break;
        case ELFOSABI_LINUX:
            printf("Linux\n");
            break;
        case ELFOSABI_SOLARIS:
            printf("Solaris\n");
            break;
        case ELFOSABI_IRIX:
            printf("IRIX\n");
            break;
        case ELFOSABI_FREEBSD:
            printf("FreeBSD\n");
            break;
        case ELFOSABI_TRU64:
            printf("TRU64 UNIX\n");
            break;
        case ELFOSABI_ARM:
            printf("ARM architecture\n");
            break;
        case ELFOSABI_STANDALONE:
            printf("Standalone (embedded) application\n");
            break;
        default:
            printf("<unknown: %x>\n", e_ident[EI_OSABI]);
    }
}

void print_abi(unsigned char *e_ident)
{
    printf("  ABI Version:                       %d\n", e_ident[EI_ABIVERSION]);
}

/**
 * print_type - Function that prints the ELF file type.
 * @e_type: The ELF file type.
 * @e_ident: Pointer to the ELF identification bytes.
 *
 * The ELF file type tells the purpose of the file.
 */
void print_type(unsigned int e_type, unsigned char *e_ident)
{
    printf("  Type:                              ");
    switch (e_type)
    {
        case ET_NONE:
            printf("NONE (Unknown type)\n");
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
            printf("<unknown: %x>\n", e_ident[EI_TYPE]);
    }
}

void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
    printf("  Entry point address:               0x%lx\n", e_entry);
}

/**
 * close_elf - Closes the file descriptor of the ELF file.
 * @elf: The file descriptor of the ELF file.
 */
void close_elf(int elf)
{
    close(elf);
}
