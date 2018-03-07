Welcome to the Level 2
This level is going to be fairly easy. You basically implement the Descriptor Tables
The x86 Architecture processors use two 'Descriptor Tables' to hold information related to
various things.
These tables, the Global Descriptor Table (GDT) and the Interrupt Descriptor Table (IDT), are
used by the processor for defining security and memory usage restrictions and mapping 
Interrupt Numbers to Functions (vectors) to be called when they are fired respectively.

Initializing IDT and GDT are important steps as they define a lot about our OS, and thats how
the CPU gets to know how our OS works.

GDT would be used in the future when you may want to go from the 'Ring 0' to higher and 
more restricted 'Ring 3' or User mode. Dont worry if you dont understand these terms, Just
Google them ;)
