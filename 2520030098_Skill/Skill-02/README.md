Skill-02: Interactive Command Loop and Keyboard Input

Interactive Command Loop

1. Create the Main Loop: Use a while loop to repeatedly accept input from the user. The loop continues until the user enters the exit command.
2. Display the Prompt: Display myshell> before every new input to indicate that the program is ready to receive a command.
3. Accept User Input: Use the read() system call to receive input from the keyboard and store it in the buf[100] input buffer.
4. Check the Exit Condition: After reading the input, check whether the user entered exit. If the input is exit, terminate the loop and display Shell exited.
5. Control Flow: The program follows this sequence:
Start → Display Prompt → Read Input → Check Exit → Display Input → Repeat
If the user enters exit, the program stops.
6. Testing: Test the program with different inputs such as hello, ls, welcome, and os practical. Also test exit to check whether the program terminates correctly.

Keyboard Input and Command Handling

1. Capture Keyboard Input: Use the read() system call to capture the characters entered by the user through the keyboard.

2. Manage the Input Buffer: Use the buf[100] character array to temporarily store the user's input.

3. Process the Input: After the user presses Enter, the program processes the entered text and displays it on the screen.

4. Support Multi-Character Input: The program accepts inputs containing multiple characters, such as hello, welcome, process, and os practical.

5. Test User Interaction: Enter different types of input and check whether they are displayed correctly. Finally, enter exit to verify that the program terminates properly.
