package test;

//Homework 2-21.7

import java.util.Scanner;

public class Triangle {
	int N = 5;
	int[][] A = new int[N][N];
	int[] B = new int[N*(N+1)/2];
	static Scanner keyboard = new Scanner(System.in);
	
/************************************************************************/
	public void CreateDownTriangle() {
		int tri = 0, count = 1;

		for(int j = 0; j < N; j++) {
			for(int i = 0; i < N; i++) {
				if(i >= tri) 
					A[i][j] = count++;
				else
					A[i][j] = 0;
			}
			tri++;
		}
	}
/************************************************************************/
	public void extract_2Dto1D(int [][] ary2D, int[] ary1D) {
		int k = 0, n = N;

		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				k = (i + 1) * (i - 1 + 1) / 2 + j + 1;
				ary1D[k-1] = ary2D [i][j];
				//System.out.println(k);
			}
		}
	}
/************************************************************************/
	public int get1DVal(int[] ary1D, int i, int j) {

		if(i<j) return 0;
		
		int k = (i + 1) * (i - 1 + 1) / 2 + j + 1;
		return ary1D[k-1];
	}
/************************************************************************/
	public void output2D(int[][] array) {

		for(int i = 0; i < array.length; i++) {
		   for(int j = 0; j < array[i].length; j++) {
		      System.out.printf(""+array[i][j]+'\t');
		   }
		   System.out.println();
		}
	}
/************************************************************************/
	public void output1D(int[] array) {
		for(int i = 0; i < array.length; i++) {
			System.out.printf(array[i]+" ");
		}
		System.out.println();
	}
/************************************************************************/


	public static void main(String[] args) {

		Triangle triangle = new Triangle();

		
		triangle.CreateDownTriangle();
		
		System.out.println("array A:");
		triangle.output2D(triangle.A);
		System.out.println("array B:");
		triangle.output1D(triangle.B);
		System.out.println("--------------------------");

		System.out.println("extract A to B: ");
		triangle.extract_2Dto1D(triangle.A, triangle.B);
		System.out.println("array A:");
		triangle.output2D(triangle.A);
		System.out.println("array B:");
		triangle.output1D(triangle.B);
		System.out.println("--------------------------");

		System.out.printf("input A[i][j]:");
		String input = keyboard.nextLine();
		String[] input_ary = input.split(",");
		int i = Integer.parseInt(input_ary[0]);
		int j = Integer.parseInt(input_ary[1]);
		
		int result = triangle.get1DVal(triangle.B, i, j);
		System.out.println("A["+i+"]["+j+"]= "+result);
		
		/*
		System.out.println("array A:");
		triangle.output2D(triangle.A);
		System.out.println("array C:");
		triangle.output2D(C);
		*/
	}
/************************************************************************/
}
