# Massively parallel modular computations

This package offers a generic massively parrallel implementation for modular algorithms in computational algebra. In the implementation,  we separate the coordination and computations layers allowing the integration of different programming languages without the need to rewrite the entire code. It also facilitates easy editing and optimization of the implementation.  The application relies on the task-based workflow provided by [GPI-Space](http://www.gpi-space.de/) for task coordination, and uses the computer algebra  system [Singular](https://www.singular.uni-kl.de/) for computational tasks.

This application  uses the Singular dynamic module implemented by Lukas Ristau from  the repository
[framework](https://github.com/singular-gpispace/framework)  with minor modification to trigger the framework directly from the Singular interpreter. Additionaly, we have made contribution to  the serialization of data type of Singular by automating the production of filenames and unifying  the data type  to be serialize.


