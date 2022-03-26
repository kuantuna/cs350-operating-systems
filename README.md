# CS350 Operating Systems Course Repository

## Homework1

All of the necessary files for homework 1 can be found in the ./hw1/ folder. This homework is consisted of two parts. As the first part I was expected to write a linux "hello world" driver and install into the kernel and as the second part I was expected to implement a "democratic" food picker algorithm in C.

### Part 1: Hello World Device Driver

Files for this part is included in the ./hw1/hd/ folder. ```hello.c``` contains the source code of the driver and ```Makefile``` is used to compile the source code.

#### Steps:
1. Compile the source code using the ```make``` command. It will create different files, but the one we will be dealing with is ```hello.ko``` (hello kernel object).
2. Later you can use the ```insmod``` command to install ```hello.ko``` into the kernel as follows: ```sudo insmod hello.ko```
3. Now that the driver is installed into the linux kernel you can use ```lsmod``` command to see your driver's name inside all kernel modules and use ```dmesg``` command to check if the "Hello, World!" message is printed or not.
4. Finally you can use ```sudo rmmod hello``` to remove the driver we have just installed. If you run ```dmesg``` after removing the module, you now should be able to see "Goodbye, cruel world!" in the logs as well.

### Part 2: What to Eat?

Files for this part is included in the ./hw1/w2e/ folder. ```What2Eat.c``` contains the source code and ```Makefile``` is used for compilation purposes.

This game is used to choose the most prefered meal in dormitories between roommates so that they can have easier time deciding what to eat. Firstly, the game asks how many players are attending to this game. Later, it prints out a list of meals that players can choose. Then every player chooses a meal from the list.

According to people's choices the game keeps track of which meal is selected how many times. By using this, the game creates a smaller list of mostly selected meals and asks everyone again what they would like to eat from these mostly selected meals. Finally, the game prints out the mostly voted meal by saying "You are eating xyz today!".
