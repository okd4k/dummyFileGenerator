###20190609

The design so far is terrible. We can say it does not have a design at all. The conf file is not used, and the resource file location is using a macro define, instead of being setable. It only supports c/c++, but not shown in UI or code. However, I need this now and urgent, therefore just leave it there now, but keep notes of what to be done.

0. fix logic bugs in the code, but maybe it should be refined or no need to be done after part 2.
1. using a global conf file, or a setable conf file, indicating the resource file locations.
2. refactor the source code, using an abstract class, and create different classes for different languages. For different languages, comment notations, header files should be considered.
3. Optimise interface, and maybe add a way to input using parameters.
4. unit tests.