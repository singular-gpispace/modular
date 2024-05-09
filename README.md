# Massively parallel modular computations

This package offers a generic massively parrallel implementation for modular algorithms in computational algebra. In the implementation,  we separate the coordination and computations layers allowing the integration of different programming languages without the need to rewrite the entire code. It also facilitates easy editing and optimization of the implementation.  The application relies on the task-based workflow provided by [GPI-Space](http://www.gpi-space.de/) for task coordination, and uses the computer algebra  system [Singular](https://www.singular.uni-kl.de/) for computational tasks.

This application  uses the Singular dynamic module implemented by Lukas Ristau from  the repository
[framework](https://github.com/singular-gpispace/framework)  with minor modification to trigger the framework directly from the Singular interpreter. Additionaly, we have made contribution to  the serialization of data type of Singular by automating the production of filenames and unifying  the data type  to be serialize.

We demonstrate the practical application of the framework in computational algebra, specifically by computing Groebner bases in characteristic 0. 
Additionally, in the field of birational geometry, we use the framework to compute the image of a rational map, also in characteristic 0. We highlight that the entirety or a part of this application can be used for a diverse range of problems, such as the  generic two-into-one machinery in the coordination layer.

To use the framework, installing Singular, GPI-Space, along with their dependencies, and the project code are required. 
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
Note, this needs to be set again if you open a new terminal session (preferably set it automatically by adding the line to your .profile file).

## Install Spack
If Spack is not already present in the above directory, clone Spack from Github:
```bash
git clone https://github.com/spack/spack.git $software_ROOT/spack

```
We check out verison v0.21 of Spack (the current version):
```bash
cd $software_ROOT/spack
git checkout releases/v0.21
cd $software_ROOT

```
Spack requires a couple of standard system packages to be present. For example, on an Ubuntu machines they can be installed by the following commands (which typically require sudo privilege)

```bash
sudo apt update

```
```bash
sudo apt install build-essential ca-certificates coreutils curl environment-modules gfortran git gpg lsb-release python3 python3-distutils python3-venv unzip zip

```

To be able to use spack from the command line, run the setup script:
```bash
. $software_ROOT/spack/share/spack/setup-env.sh

```
Note, this script needs to be executed again if you open a new terminal session (preferably set it automatically by adding the line to your .profile file).

Finally, Spack needs to boostrap clingo.  This can be done by concretizing any
spec, for example
```bash
spack spec zlib

```

Note: If you experience connection timeouts due to a slow internet connection you can set in the following file the variable `connect_timeout` to a larger value.
```bash
vim $software_ROOT/spack/etc/spack/defaults/config.yaml

```

### How to uninstall Spack
Note that Spack can be uninstalled by just deleting its directory and its configuration files. Be CAREFUL to do that, since it will delete your Spack setup. Typically you do NOT want to do that now, so the code is commented out. It can be useful if your Spack installation is broken:

```bash
#cd
#rm -rf $software_ROOT/spack/
#rm -rf .spack

```
## Install modular

Once you have installed Spack, our package can be installed with just three lines of code.

Clone the Singular/GPI-Space package repository into this directory:
```bash
git clone https://github.com/singular-gpispace/spack-packages.git $software_ROOT/spack-packages

```

Add the Singular/GPI-Space package repository to the Spack installation:
```bash
spack repo add $software_ROOT/spack-packages

```

Finally, install modular:
```bash
spack install modular

```
Optionally, the modular framework can be installed in a Spack environment by replacing the last line of code with the following commands.

Create an environment:
```bash
spack env create myenv

```
Activate the environment:
```bash
spack env activate -p myenv

```
Add the abstract specs of modular to the environment:

```bash
spack add modular

```

Concretize the environment:
```bash
spack concretize

```
Install the environment
```bash
spack install

```

Note, this may take quite a bit of time, when doing the initial installation, as it needs to build GPI-Space and Singular
including dependencies. Installing further components of the framework or updating is then typically quick.

## Load modular

Once modular is installed, to use modular load the package via:
```bash
spack load modular

```
If modular is installed in an environment, run the following command to activate the environment:
```bash
spack env activate -p myenv

```
After usage of the package, we can deactivate the environment via the command:
```bash
spack env deactivate

```

Note, that this command needs to be executed again if you open a new terminal session. In particular, the environment variable `MODULAR_INSTALL_DIR` is available only after executing this command.

## Set up ssh

GPI-Space requires a working SSH environment with a password-less
SSH-key when using the SSH RIF strategy. To ensure this, 
leave the password field empty when generating your ssh keypair.

By default, `${HOME}/.ssh/id_rsa` is used for authentication. If no such key exists,
```bash
ssh-keygen -t rsa -b 4096 -N '' -f "${HOME}/.ssh/id_rsa"

```
can be used to create one. 

If you compute on your personal machine, there must run an ssh server. On an Ubuntu machine, the respective package can be installed by:

```bash
sudo apt install openssh-server

```

Your key has to be registered with the machine you want to compute on. On a cluster with shared home directory, this only has to be done on one machine. For example, if you compute on your personal machine, you can register the key with:
```bash
ssh-copy-id -f -i "${HOME}/.ssh/id_rsa" "${HOSTNAME}"

```
# Example of how to use the modular package
If you start in a new terminal session (and did not configure your terminal to do this automatically) make sure to set `software_ROOT` and run the `setup-env.sh` script. Make also sure to load the modular package in Spack. As discussed above this can be done by:

```bash
export software_ROOT=~/singular-gpispace
. $software_ROOT/spack/share/spack/setup-env.sh
spack load modular

```
## Setup directories and example files
First, we copy the needed library for the example into `software_ROOT` directory.
```bash
cp $MODULAR_INSTALL_DIR/share/examples/modulargp.lib $software_ROOT

```
We create a nodefile, which contains the names of the nodes used for computations with our framework. In our example, it just contains the result of hostname.

```bash
hostname > $software_ROOT/nodefile

```
Moreover, we need a directory for temporary files, which should be accessible from all machines involved in the computation:

```bash
mkdir -p $software_ROOT/tempdir

```
## Start the monitor

Optionally, but recommended: We start the GPI-Space Monitor to display computations in form of a Gantt diagram (to do so, you need an X-Server running).
In case you do not want to use the monitor, you should not set in Singular the fields options.loghostfile and options.logport of the GPI-Space configuration token (see below). In order to use the GPI-Space Monitor, we need a loghostfile with the name of the machine running the monitor.

```bash
hostname > $software_ROOT/loghostfile

```

On this machine, start the monitor, specifying a port number where the monitor will receive information from GPI-Space. The same port has to be specified in Singular in the field options.logport.

```bash
gspc-monitor --port 9876 &

```
## Start Singular

We start Singular in the directory where it will have direct access to all relevant directories we just created, telling it also where to find the libraries for our framework:

```bash
cd $software_ROOT
SINGULARPATH="$MODULAR_INSTALL_DIR"  Singular

```
We will provide two examples of computation using the package. The first is for the computation of the image of a rational map. The second is for the computation of Groebner bases.

##  Example for modular computation of the image of a rational map.
In this example, we compute the image of a quintic plane curve by the the degree 5 Veronese embedding. In Singular, now do what follows below.

```bash
LIB "modulargspc.lib";

configToken gc = configure_gspc();
gc.options.tmpdir = "tempdir";
gc.options.nodefile = "nodefile";
gc.options.procspernode = 4;
gc.options.loghostfile = "loghostfile";
gc.options.logport = 9876;

ring R=0,(t0,t1,t2),dp;
ideal I = t1^5+10*t1^4*t2+20*t1^3*t2^2+130*t1^2*t2^3-20*t1*t2^4+20*t2^5-2*t1^4*t0-40*t1^3*t2*t0-150*t1^2*t2^2*t0-90*t1*t2^3*t0-40*t2^4*t0+t1^3*t0^2+30*t1^2*t2*t0^2+110*t1*t2^2*t0^2+20*t2^3*t0^2;
I;
ideal phi = maxideal(3);
phi;

def result = gspc_modimage(phi,I,gc,12,3,20,20,24);
setring result;
im;

```
## Example for the modular computation of a Gröbner basis over the rationals


