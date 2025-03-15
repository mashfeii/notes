---
id: conteinerization
aliases: []
tags: []
---

# Application and Dependencies Conteinerization

<!--toc:start-->

- [Application and Dependencies Conteinerization](#application-and-dependencies-conteinerization)

  - [Docker](#docker)
    - [Main Components](#main-components)
    - [`Dockerfile`](#dockerfile)
  - [Docker Compose](#docker-compose)
  <!--toc:end-->

- Different OS versions
  - Development on Windows, serve on Linux
  - Locally works, but not in production
- Dependepcies
  - Different versions
  - Dependencies updates broke the app
- Environment settings
- Monolithic VM

```mermaid
timeline
title Virtualization development
1960: Recourses separation on mainframes
    : Definition of virtual OS
    : CP-40 and CP-67
1970: IBM VM/370
    : chroot (1979)
1990: Linux VServer (1998)
    : Hypervisors VMware (1999)
2000: Xen (2003)
    : OpenVZ (2005)
    : KVM (2007)
    : cgroups (2007)
    : LXC (2008)
2010: Docker (2013)
    : Kubernetes (2015)
2020: Podman
    : Conteinerd
    : CRI-O
    : Wasm
```

## Docker

- Namespaces
  Environment isolation
- Cgroups
  Allow containers to use shared resources
- UnionFS
  Separation and reusability of layers
- containerd & runC
  - daemon on host-system, which manages container lifecycle
  - library-wrapper for container runtime

### Main Components

- Docker Daemon - manages containers
- Docker CLI - working interface
- Docker Images - container templates
- Docker Containers - running instances of images
- Docker Registry - central repository for container images
- Docker Volumes - shared data between containers (databases, files, etc.)
- Docker Networks - virtual network for containers

### `Dockerfile`

- Instruction for image creation
- Each instruction creates intermidiate image layer
- Final build is done by Docker daemon
- For optimization layers are cached

```mermaid
flowchart LR;
A(FROM python:last) --> B(Layer 1 - Base layer);
C(RUN mkdir -p /app) --> D(Layer 2);
E(COPY . /app) --> F(Layer 3);
```

![dockerfile](/attachments/dockerfile.png)

## Docker Compose

```mermaid
flowchart LR;
A(docker-compose.yaml)-->B(Docker Compose);
B-->C(Docker Image);
B-->D(Docker Image);
B-->E(DockerFile);
C-->F(Docker Container);
D-->G(Docker Container);
E-->H(Docker Image);
H-->I(Docker Container);
```

`docker-compose.yaml`

```aml
services:
  service_name
  build:
    context:
    dockerfile: Dockerfile
  container_name:
  restart:
  ports:
  environment:
  volumes:
  depends_on:

volumes:
networks:
```
