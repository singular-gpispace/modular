# Massively parallel modular computations

This package offers a generic massively parrallel implementation for modular algorithms in computational algebra. In the implementation,  we separate the coordination and computations layers allowing the integration of different programming languages without the need to rewrite the entire code. It also facilitates easy editing and optimization of the implementation.  The application relies on the task-based workflow provided by [GPI-Space](http://www.gpi-space.de/) for task coordination, and uses the computer algebra  system [Singular](https://www.singular.uni-kl.de/) for computational tasks.

This application  uses the Singular dynamic module implemented by Lukas Ristau from  the repository
[framework](https://github.com/singular-gpispace/framework)  with minor modification to trigger the framework directly from the Singular interpreter. Additionaly, we have made contribution to  the serialization of data type of Singular by automating the production of filenames and unifying  the data type  to be serialize.

We demonstrate the practical application of the framework in computational algebra, specifically by computing Groebner bases in characteristic 0. 
Additionally, in the field of birational geometry, we use the framework to compute the image of a rational map, also in characteristic 0. We highlight that the entirety or a part of this application can be used for a diverse range of problems, such as the  generic two-into-one machinery in the coordination layer.

To use the framework, installing Singular, GPI-Space, along with their dependencies, and the project code is required. 
We offer two distinct installation methods. The preferred approach involves using the supercomputing package manager Spack, 
which automates the handling of all dependencies. Alternatively, a manual installation of components is available,
serving as anoption if the installation via Spack fails on the target system.


# Installation using Spack
Spack is a package manager specifically aimed at handling software installations in supercomputing environments, but
usable on anything from a personal computer to an HPC cluster. It supports Linux and macOS (note that the Singular/GPI-Space
framework and hence our package requires Linux).

We will assume that the user has some directory path with read and
write access. In the following, we assume this path is set as the environment variable
`software_ROOT`, as well as `install_ROOT`:

```bash
export software_ROOT=~/singular-gpispace
export install_ROOT=~/singular-gpispace

```



