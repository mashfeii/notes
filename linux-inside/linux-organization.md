# How everything works on Linux?

## Bios

What is going on after turning on? CPU Registers are set to default values and CPU goes to the **reset vector** -
constant value containing `jmp` instruction to the **BIOS code**
Bios itself first does **POST** (Power On Self Test):

1. Checks is everything fine with BIOS **flash memory**
2. Initializing equipment: processor, memory, interfaces
3. Launches internal BIOS of graphic cards, network cards, etc.

If something went wrong POST uses POST card with special digital representation of error codes or Bipper thing that can
only beep, by such beeps it represents error codes (certain number of short and long ones)

## Disks

In the 90s **MBR** (Master Boot Record) was used, it is first 512 bytes on disk before partitions (4 maximum), also,
such disk implementation limited maximum capacity by 2 Tb

## UEFI

1. **UEFI** is a new standard
2. UEFI architecture is much more complicated it tries to become general interface
3. UEFI is able to read file system _fat32_
4. UEFI has _Secure boot_ section

## Example of loader for by GRUB2

1. Loads peripheral drivers (`ls /boot/grub/x86_64-efi/`)
2. Allows choosing between several boot systems
3. Booting logs can be shown by `cat /boot/grub/grub.cfg`

## Kernel

1. Kernel is just a **binary file** [script for
   verification](https://github.com/tovalds/linux/blob/master/scripts/extract-vmlinux)
2. In fact GRUB just executes binary file with certain flags (`cat /proc/cmdline`)

### Initialization process

bootloader → kernel loaded to RAM → kernel uncompressed → kernel started with parameters → initramfs

## Init

Why we need such process?

1. Managing the order in which processes are started
2. Managing all running processes
3. Mounting file systems
4. From now - managing all system in general

**systemd** is the mostly used `init`, why so?

1. Enough number of additional utilities for managing system
2. System for controlling demons and targets
3. Syntaxes for demons creation

## PXE (Preboot eXecution Environment)

1. Protocols for dynamic receipt IP address (initially - BOOTP, now - DHCP)
2. Protocols for delivering OS image - TFTP

## Types of file systems

### FAT

1. Understand almost all OS
2. Simple structure
3. Non-journalized
4. Very limited in capacity

### ext4

- Extents
- Hash-tree
- Inoids are finite
- Journalized
- Default Debian, Ubuntu and more

### btrfs

- Works well with SSD
- B-tree
- Copy-on-write + snapshots
- LVM and RAID from the box
- Suballocation
- Default openSUSE

## File system configuration

### Caching

1. _Page Cache_ - uploading data into memory
2. _Dirty Cache_ - changes in memory but not uploaded to memory yet
