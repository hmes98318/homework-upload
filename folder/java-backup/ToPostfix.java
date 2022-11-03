package test;

// Homework 3-32.4

import java.io.*;
import java.util.*;


public class ToPostfix {
	static Scanner keyboard = new Scanner(System.in);

	Map<String, Integer> infix_weight = new HashMap<String, Integer>() {
		{
	        put("END", 0);
	        put(")", 1);
			put("-", 2);
	        put("+", 2);
	        put("*", 3);
	        put("/", 3);
	        put("%", 3);
	        put("^", 4);
	        put("(", 5);
		}
	};

	Map<String, Integer> opers_weight = new HashMap<String, Integer>() {
		{
	        put("END", 0);
	        put("(", 1);
			put("-", 2);
	        put("+", 2);
	        put("*", 3);
	        put("/", 3);
	        put("%", 3);
	        put("^", 4);
	        //put(")", 5);
		}
	};
/************************************************************************/
	public ArrayList<String> infixSplit(String infix) {
		
		infix = infix.replaceAll(" ", "");
		char[] infix_ary = infix.toCharArray();
		int infix_length = infix.length();
		
		ArrayList<String> list = new ArrayList<>();
		
		for(int i = 0; i < infix_length; i++) {
			char c = infix_ary[i];

			if(isNumber(c)) {
				int count = 0, j = i;
				
				while(j < infix_length && isNumber(infix_ary[j])) {
					count = count * 10 + (int)(infix_ary[j++] - '0');
				}
				i = j -1;
				list.add(Integer.toString(count));
			}
			else {
				if(isOperands(String.valueOf(c))) list.add(String.valueOf(c));
			}
		}
		return list;
	}
/************************************************************************/
	public ArrayList<String> infixToPostfix(ArrayList<String> infix){
		
		ArrayList<String> list = new ArrayList<>();
		Deque<String> opers = new ArrayDeque<>();

		opers.addLast("END");
		
		for(String str : infix) {
			switch(str) {

			case ")":
				while(!opers.peekLast().equals("(")) {
					list.add(opers.pollLast());
				}
				opers.pollLast();
				break;

			case"+":
			case"-":
			case"*":
			case"/":
			case"%":
			case"(":			
				while(opers_weight.get(opers.peekLast()) >= infix_weight.get(str)) {
					list.add(opers.pollLast());
				}
				opers.addLast(str);
				break;

			default :
				list.add(str);
			}
		}

		while(!opers.peekLast().equals("END")) {
			list.add(opers.pollLast());
		}
		return list;
	}
/************************************************************************/
	public int postfixCalculate(ArrayList<String> postfix) {
		
		Deque<Integer> nums = new ArrayDeque<>();
		int result = 0;
		
		for(String str : postfix) {
			if(!isOperands(str)) {
				int n = Integer.parseInt(str);
				nums.addLast(n);
			}
			else {
				calculate(nums, str);
			}
		}
		return nums.peekLast();
	}
/************************************************************************/
	public void calculate(Deque<Integer> nums, String opers) {
		int b = nums.pollLast(),
			a = nums.pollLast(),
			ans = 0;

		if(opers.equals("+")) ans = a + b;
		else if(opers.equals("-")) ans = a - b;
		else if(opers.equals("*")) ans = a * b;
		else if(opers.equals("/")) ans = a / b;
		else if(opers.equals("%")) ans = a % b;
		else if(opers.equals("^")) ans = (int)Math.pow(a, b);

		nums.addLast(ans);
	}
/************************************************************************/
	public boolean isNumber(char c) {
		return Character.isDigit(c);
	}
/************************************************************************/
	public boolean isOperands(String str) {
	    return str.equals("+") || 
	    	   str.equals("-") || 
	    	   str.equals("*") || 
	    	   str.equals("/") || 
	    	   str.equals("%") || 
	    	   str.equals("^") || 
	    	   str.equals("(") || 
	    	   str.equals(")");
	}
/************************************************************************/

	
	public static void main(String[] args) {
		ToPostfix postfix = new ToPostfix();
		
		String infix = "10*(9+1*6)";
		
		while(true) {
			System.out.print("\n--------------------------\n");
			System.out.print("   -- valid operands --\n");
			System.out.print("  +, -, *, /, %, ^, (, )");
			System.out.print("\n--------------------------\n");
			
			System.out.printf("\nEnter infix: ");
			infix = keyboard.nextLine();

			
			ArrayList<String> infix_ary = postfix.infixSplit(infix);
			System.out.print("Infix: ");
			for (String str : infix_ary) {
		    	System.out.print(str+",");
		    }
			
			System.out.println();

			ArrayList<String> postfix_ary = postfix.infixToPostfix(infix_ary);
			System.out.print("Postfix: ");
			for (String str : postfix_ary) {
		    	System.out.print(str+",");
		    }

			System.out.println();

			int calculation_result = postfix.postfixCalculate(postfix_ary);
			System.out.print("Ans: "+calculation_result);
		}
	}
/************************************************************************/
}
