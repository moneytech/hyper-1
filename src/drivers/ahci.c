#include <pci.h>
#include <stdio.h>

#define DRV_NAME "ahci"
#define VENDOR_ID 0x8086
#define DEVICE_ID 0x2922

static struct pci_device_id ahci_pci_id = {
	PCI_DEVICE(VENDOR_ID, DEVICE_ID),
};

static int ahci_probe(struct pci_dev *dev)
{
	(void)dev;
	printf("AHCI driver called\n");
	return 0;
}

static struct device_driver_ops ahci_drv_ops = {
	.probe = ahci_probe,
};

static struct pci_driver ahci_pci_drv = {
	.drv = {
		.name = DRV_NAME,
		.ops = &ahci_drv_ops,
	},
	.id = &ahci_pci_id,
};

struct pci_driver *register_ahci(void)
{
	list_init(&ahci_pci_drv.next);
	return &ahci_pci_drv;
}