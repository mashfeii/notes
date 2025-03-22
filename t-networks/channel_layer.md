---
id: channel_layer
aliases:
  - channel layer
tags:
  - networks
  - channels
  - t-academy
---

# Networks - Channel Layer

## Channel (Data Link) Layer. Ethernet

- Channel layer is responsible for communication between network interface cards (NICs) endpoint devices.
- It allows higher layers to access to physical layer and encapsulate packets of 3d layer (IPv4 IPv6) into
  frames of 2nd layer (Ethernet).
- Responsible for error handling and removing damaged frames.
- Devices on that level: switch, Wi-Fi access point.

### Sublevels

- **Logical Link Control (LLC)**: is acting between network software on higher levels and hardware on lower ones.
- **Media Access Control (MAC)**: is responsible for addressing, data encapsulation and access to the layer of data
  transmission.

## Physical and Logical Topologies

Network topology describes the arrangement or interactions of the network devices as well as interconnections between
them.

There are two types of network topologies:

- **Physical topology**: shows physical connections and devices interactions.
- **Logical topology**: describes virtual connections between devices using devices interfaces and IP schemes, VLANs,
  VRFs, etc.
