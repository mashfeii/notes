# 2024-05-30 09:07

## Stack of protocols

Stack of protocols TCP/IP (a set of rules for information exchange) is the
basis of internet work.

Every computer (node, host) within the Internet have unique address - IP-address
(Internet Protocol Address), e.g.: 195.34.32.116

Because it is not the computers themselves that exchange the information, but the
applications on them, we need to know the number of application - it's **port**.
(E.g.: mailing service has port 25 - its "listens" to 25 port, web-service - 80,
FTP - 21 and so on)

> [!NOTE]+ Analogy with mailing service
> Home address - computer IP
> Apartment number - port number

In computer networks working according to TCP/IP protocols, the analogue to the
paper letter is a **packet** that contains exchanging data and sender and
recipient addresses

> [!NOTE]+ Analogy of packet with paper letter
> _Source address_:
> IP: 82.145.58.33
> Port: 2049
> _Destination address_:
> IP: 192.43.213.234
> Port: 53
> _Packet data_

As a rule, interaction is carried out by "client-server" scheme.
"Client" makes a request for information, server takes the request, processes it
and return the result

The most programs on home pc are "clients": email client Outlook,
internet-browsers, etc.
Port numbers on client are not fixed, as server has, but dynamically assigned by
OS.
Fixed server ports are typically has numbers up to 1024 (but there are
exceptions), and client start from 1024.

> [!NOTE]
> Every digital IP-address is connected with alphanumeric designation
> (обозначением). For example, instead of 82.146.49.55 one can use the name
> www.ofnet.ru

The _domain name server_ (**DNS**) is responsible for converting a domain name
into a digital IP-address.

Provider explicitly (for manual connection settings) or implicitly (by automatic
connection settings) provides to one an IP-address of DNS. On computer with that
IP-address works application (name server), that knows all the domain names in
the Internet and corresponding to them IP-addressed.

> [!NOTE]+ Example of interaction for DNS and name server on client
> _Request_: which IP-address respond to name *www.ofnet.ru*?
> _Server response_: 82.146.49.55

Example for testing own computer:
Through the console on Windows, one can with command `netstat -an` find all the
connections between sockets of PC and sockets of remote nodes (hosts, etc.)
If some remote (external) address has stranger addresses with 25 (mailing
service) port, this may mean that one's computer establish (установил)
a connection with some mailing service and send through it some emails.

Also, the understanding of work TCP/IP is necessary for firewall
customization - this program is used for filtering packets - your "own" and
"enemy's"
For example, if firewall says you, that someone wants to establish the
connection with some port of your computer, you choose - allow or prohibit

_Some general ports_:

- `135-139` - these are used by Windows for general resources access -
  directories, printers, etc. One should not open such ports outside (to the
  local network or Internet). They should be closed by firewall.
- `21` - FTP server
- `25` - email SMTP server, through it your email client send the emails.
  IP-address of SMTP server and its port should be specified in your email
  settings.
- `110` - POP3 server. Through it your email client take letters from your
  mailbox. IP-address of POP3 server and its port also should be specified in your
  email settings.
- `80` - WEB-server
- `3128, 8080` - proxy-servers (they are configured in browser settings)
