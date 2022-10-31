package test;

// Homework 3-32.4

import java.io.*;
import java.util.*;
import java.util.Stack;


public class ToPostfix {
	static Scanner keyboard = new Scanner(System.in);

	Map<Character, Integer> weight = new HashMap<Character, Integer>() {
		{
			put('-', 1);
	        put('+', 1);
	        put('*', 2);
	        put('/', 2);
	        put('%', 2);
	        put('^', 3);
		}
	};

/************************************************************************/
	public int InfixToPostfix(String infix) {

		infix = infix.replaceAll(" ", "");
		char[] infix_ary = infix.toCharArray();
		int infix_length = infix.length();
		
		Deque<Integer> nums = new ArrayDeque<>();
		Deque<Character> opers = new ArrayDeque<>();
		
		nums.addLast(0);
		
		for(int i = 0; i < infix_length; i++) {

			if(infix_ary[i] == '(') 
				opers.addLast(infix_ary[i]);

			else if(infix_ary[i] == ')') {
				while(!opers.isEmpty()) {
					if(opers.peekLast() != '(')
						calculate(nums, opers);
					else {
						opers.pollLast();
						break;
					}
				}
			}

			else {
				if(isNumber(infix_ary[i])) {
					int count = 0, j = i;
					
					while(j < infix_length && isNumber(infix_ary[j])) {
						count = count * 10 + (int)(infix_ary[j++] - '0');
					}
					i = j -1;
					nums.addLast(count);
				}
				else {
					while(!opers.isEmpty() && opers.peekLast() != '(') {
						char opersLast = opers.peekLast();

						if(weight.get(opersLast) >= weight.get(infix_ary[i]))
							calculate(nums, opers);
						else
							break;
					}
					opers.addLast(infix_ary[i]);
				}
			}
		}

		while(!opers.isEmpty() && opers.peekLast() != '(') {
			calculate(nums, opers);
		}
		return nums.peekLast();
	}
/************************************************************************/
	public void calculate(Deque<Integer> nums, Deque<Character> opers) {
		if(nums.isEmpty() || nums.size() < 2) return;
		if(opers.isEmpty()) return;
		
		int b = nums.pollLast(),
			a = nums.pollLast();
		char o = opers.pollLast();
		int ans = 0;
		
		if(o == '+') ans = a + b;
		else if(o == '-') ans = a - b;
		else if(o == '*') ans = a * b;
		else if(o == '/') ans = a / b;
		else if(o == '%') ans = a % b;
		else if(o == '^') ans = (int)Math.pow(a, b);
		
		nums.addLast(ans);
	}
/************************************************************************/
	public boolean isNumber(char c) {
		return Character.isDigit(c);
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
		ToPostfix topost = new ToPostfix();
		
		//String infix = "10*(9+1*6)";
		
		while(true) {
			System.out.print("\n--------------------------\n");
			System.out.print("   -- valid operands --\n");
			System.out.print("  +, -, *, /, %, ^, (, )");
			System.out.print("\n--------------------------\n");


			System.out.printf("\nEnter infix: ");
			String input = keyboard.nextLine();

			char[] input_ary = input.toCharArray();
			ArrayList<Character> parenthes = new ArrayList<Character>();
			for(int i = 0; i < input_ary.length; i++) {
				if(input_ary[i] == '(' || input_ary[i] == ')')
					parenthes.add(input_ary[i]);
			}

			if(!validParenthes(parenthes)) {
				System.out.println("\nInvalid parentheses, try again");
				continue;
			}


			System.out.println("Ans: "+topost.InfixToPostfix(input));
		}
	}
/************************************************************************/
}
