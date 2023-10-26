#include "main.h"
/**
 * print_elf_header - fxn that prints elf header info
 * @hdr: elf header structure
 * Return: nothing
 */

void print_elf_header(struct elf_hdr *hdr)
{
	int i;

	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x ", hdr->e_ident[i]);
	printf("\n");
	printf("  Class:                             ELF64\n");
	printf("  Data:                            2's complement, little endian\n");
	printf("  Version:                           1 (current)\n");
	printf("  OS/ABI:                            UNIX - System V\n");
	printf("  ABI Version:                       0\n");
	printf("  Type:                              EXEC (Executable file)\n");
	printf("  Entry point address:               0x%lx\n", hdr->e_entry);
}

/**
 * main - program entry point
 * @argc: number of arguments
 * @argv: argument array
 * Return: 0 always success
 */

int main(int argc, char **argv)
{
	int fd;
	struct elf_hdr elf_header;
	
	if (argc != 2)
	{
		fprintf(stderr, "Usage: elf_header elf_filename\n");
		return (98);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (98);
	}
	if (read(fd, &elf_header, sizeof(elf_header)) != sizeof(elf_header))
	{
		fprintf(stderr, "Error reading ELF header\n");
		return (98);
	}

	if (elf_header.e_ident[EI_MAG0] != ELFMAG0 ||
			elf_header.e_ident[EI_MAG1] != ELFMAG1 ||
			elf_header.e_ident[EI_MAG2] != ELFMAG2 ||
			elf_header.e_ident[EI_MAG3] != ELFMAG3)
	{
		fprintf(stderr, "File is not an ELF file\n");
		return (98);
	}

	print_elf_header(&elf_header);

	close(fd);
	return (0);
}
