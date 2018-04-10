#  Module 1 - Fundamentals of System Hardware

----
## :notebook: Notes :notebook:
----

**Concept**: Most devices inside the computer are either IO devices or they're processing

### What is a computer?
    An electromechanical device that takes input, does processing and produces output
    
### What is a mainframe?
    A very large computer that act as a central point for all computing done

### CPU or Central Processing Unit?
    Brain of the computer. CPU has really little memory (measured in bytes) called registers, temporary storage to do immediate processing. CPU may have cache memory to perform more quickly than main memory. 

### Main Memory?
    Where code and data are stored, but is only temporary especially when the computer gets turned off, the memory will be lost

### Permanent storage / secondary storage?
    Where data is stored permanently, so the memory that is lost from main memory gets stored here instead

### Communication between devices is done by?
    A bus, little copper lines to send bidirectional communication between devices. System bus is the main pathway between CPU and main memory.

### Machine language vs Higher level language
    The machine language instructions are designed physically into the chip.

### Fetch-decode-execute cycle
    Fetch instruction from main memory -> into a register in CPU known as "instruction register" -> CPU decodes instruction register -> CPU executes the instruction. Occurs in ~10 nanoseconds.
    
### Memory Hierarchy

**Concept of Hierarchy** - expensive to run code directly on CPU because CPU does not fit much memory. Significant amount of money costs if add more memory onto CPU, so a memory hierarchy is adopted. 

    Register (B) -> Cache (MB) -> RAM/DDR/Main Memory (GB) - where code is going to come from to load into register one by one, but not permanent data -> Secondary Storage (TB) - where can store data permanently -> Tertiary storage - USB, CD-ROM, flash drives
    Lower hierarchy = slower load but still measured in nanoseconds 

### RAM or Random Access Memory
    Can access any byte of main memory independently and at the same amount of time. When a program is ran, machine language instructions are brought into RAM and one by one fetched by the CPU into the instruction register and then processed.

### Secondary Storage
    HDD or SSD. 
        In HDD, the head moves in and out on different radii, polar coordinates to a specific point on the disk to either read or write. Accessing data causes movement and movement from innermost to outermost radii takes some time. 
        In SSD, all data stored electrically in chips. Even if power removed from chip, data is still stored and all data can be accessed in the same amount of time (For Example: first saved and last saved data can be accessed with the same amount of time).
        SSD = more energy efficient b/c does not have a spinning disk & better performance except less storage than HDD.
        
### Networking
    Can access data anywhere via internet
    
### Networking - Protocol
    Two computers are going to be talking and need to understand the complete language. 
        How do we know when to start sending data?
        How do we know who its from?
        How do we know who it's going to?

### Networking - Ethernet
    Uses both protocol and wired connection. 100MB connection over copper

### Networking - 802.11
    Defined by IEEE. 802.11 - B, N, AC protocols over wifi
    
### Networking - ATM
    Asynchronous Transfer Mode used in networks for high capacity links 

### Packets
    In order to send data, it is encapsulated into a packet and given to application protocol, which then adds a header for information for the receiver to understand what's being sent. When a packet moves to the logical protocol, it adds another header on top of the application layer's header until data is sent to the physical network. 

### Common Packet Layers
    Application Layer
        HTTP - Hyper Text Transport Protocol
        SMTP - Simple Mail Transport Protocol
        IMAP - Internet Mail Access Protocol
    Logical or (Network Layer)
        Two Layers
            Oriented or connection less (ordering and guaranteeing delivery of packets)
                UDP - Connection less connection
                TCP - Connection oriented connection
            Global Delivery Packets (unique to each computer)
                IP - Internet Protocol
    Physical Layer
        Adds header and footer (indicating the end)
            For Example: Ethernet
            
    Watching a video = Header for each -> HTTP + TCP + IP + Ethernet header to know where packets are coming from and to
