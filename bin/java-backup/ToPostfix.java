package test;

// Homework 3-32.4

import java.util.Scanner;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.Stack;

public class ToPostfix {
	int SIZE = 300;
    char[] infix = new char[SIZE];
	static Scanner keyboard = new Scanner(System.in);
	
/************************************************************************/
	public void arrayInit(char[] array) {
		for(int i = 0; i < array.length; i++) {
			array[i] = '#';
		}
	}
/************************************************************************/
	public void infixToPostfix() {
		int top = 0, index = 0, end_index = 0;
		char[] stack = new char[SIZE];

		//System.out.println("infixToPostfix(): "+Arrays.toString(infix));
		while(infix[end_index] != '#') {
			end_index++;
		}
		//System.out.println("end_index: "+end_index);

		stack[top] = '#';

		for(index = 0; index <= end_index; index++) {
			switch(infix[index]) {
				case '#':
					while(stack[top] != '#')
						System.out.printf("%c", stack[top--]);
					break;

				case ')':
					while(stack[top] != '(')
						System.out.printf("%c", stack[top--]);
					top--;
					break;
					
				case '(':
				case '^':
				case '*':
				case '/':
				case '%':
				case '+':
				case '-':
				    while (weight(stack[top], infix[index]) == true)
						System.out.printf("%c", stack[top--]);
				    stack[++top] = infix[index];
					break;	

				default :
					System.out.printf("%c", infix[index]);
			}
		}
	}
/************************************************************************/
	public static boolean weight(char stack_val, char infix_val) {
		int stack_index = 0, infix_index = 0;
		char[] stack_priority = {'#','(','-','+','%','/','*','^'};
		char[] infix_priority = {'#',')','-','+','%','/','*','^','('};
		
		while(stack_priority[stack_index] != stack_val) stack_index++;
		while(infix_priority[infix_index] != infix_val) infix_index++;

		return stack_index >= infix_index ? true : false;
	}
/************************************************************************/
	public static boolean validParenthes(ArrayList<Character> parenthes) {

		if(parenthes.size() %2 != 0) return false;
		
		Stack<Character> stack = new Stack<Character>();

		for(char c : parenthes) {
			if(c == '(') 
				stack.push(')');
			else
				if(stack.empty() || c != stack.pop()) return false;
		}

		if(stack.empty()) return true;
        return false;
	}
/************************************************************************/


	public static void main(String[] args) {
        ToPostfix topos = new ToPostfix();

        while(true) {
			System.out.print("\n---------------------------\n");
			System.out.print("      -- 有效運算子 --\n");
			System.out.print(" ^: 次方\n");
			System.out.print(" *: 乘\t/: 除\t%: 取餘\n");
			System.out.print(" +: 加\t\t-: 減\n");
			System.out.print(" (: 左括號\t): 右括號\n");
			System.out.print("\n---------------------------\n");


			System.out.printf("\n輸入中序運算式: ");
			String input = keyboard.nextLine();

			char[] input_ary = input.toCharArray();
			if(input_ary.length >= topos.infix.length) {
				System.out.println("\n公式過長重新輸入");
				continue;
			}


			ArrayList<Character> parenthes = new ArrayList<Character>();
			for(int i = 0; i < input_ary.length; i++) {
				if(input_ary[i] == '(' || input_ary[i] == ')')
					parenthes.add(input_ary[i]);
			}

			if(!validParenthes(parenthes)) {
				System.out.println("\n括號無效重新輸入");
				continue;
			}

			topos.arrayInit(topos.infix);

			for(int i = 0; i < input_ary.length; i++) {
				topos.infix[i] = input_ary[i];
			}

			System.out.printf("後序運算式: ");
			topos.infixToPostfix();

			System.out.println();
		}
    }
/************************************************************************/
}
