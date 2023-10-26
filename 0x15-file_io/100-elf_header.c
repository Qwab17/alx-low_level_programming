#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

/**
 * print_elf_header - Display ELF header information.
 * @header: Pointer to the ELF header structure.
 */

void print_elf_header(const Elf64_Ehdr *header)
{
	printf("Magic:   %x %x %x\n", header->e_ident[EI_MAG0], header->e_ident[EI_MAG1], header->e_ident[EI_MAG2]);
	printf("Class:   %d\n", header->e_ident[EI_CLASS]);
	printf("Data:    %d\n", header->e_ident[EI_DATA]);
	printf("Version: %d\n", header->e_ident[EI_VERSION]);
	printf("OS/ABI:  %d\n", header->e_ident[EI_OSABI]);
	printf("ABI Version: %d\n", header->e_ident[EI_ABIVERSION]);
	printf("Type:    %d\n", header->e_type);
	printf("Entry point address: 0x%lx\n", header->e_entry);
}

/**
 * main - Entry point.
 * @argc: Argument count.
 * @argv: Array of argument strings.
 * Return: 0 on success, 98 on error.
 */

int main(int argc, char *argv[])
{
	int fd;

	Elf64_Ehdr header;

	if (argc != 2) {
		dprintf(2, "Usage: %s elf_filename\n", argv[0]);
		return 98;
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1) {
		dprintf(2, "Error: Cannot open file %s\n", argv[1]);
		return 98;
	}

	if (read(fd, &header, sizeof(header)) != sizeof(header))
	{
		dprintf(2, "Error: Cannot read ELF header\n");
		close(fd);
		return 98;
	}


	if (header.e_ident[EI_MAG0] != ELFMAG0 ||
			header.e_ident[EI_MAG1] != ELFMAG1 ||
			header.e_ident[EI_MAG2] != ELFMAG2 ||
			header.e_ident[EI_MAG3] != ELFMAG3)
	{
		dprintf(2, "Error: Not an ELF file\n");
		close(fd);
		return 98;
	}

	print_elf_header(&header);
	close(fd);
	return 0;
}
