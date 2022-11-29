package homework;

// Homework 4-45.10
// 未完成: modify_f()

import java.util.Scanner;
import java.util.InputMismatchException;

class Student  {
	public int id;		// 學號
	public String name;		// 姓名
	public String gender;	// 男Male, 女Female
	public int phone;		// 電話號碼
	public String address;	// 地址
	public Student next;	// next node
}

public class List{
	static Scanner keyboard = new Scanner(System.in);
	static Student ptr, head, current, prev, temp, modifyNode;

	List()
	{
		head = new Student();
		head.next = null;
	}

/************************************************************************/
	// 依分數的高低加入
	public void insert_f(){
		System.out.println("Call insert_f().... \n");

		ptr = new Student();
		ptr.next=null;

		System.out.print("Student ID : ");			ptr.id = keyboard.nextInt();
		System.out.print("Student name : ");		ptr.name = keyboard.next();
		System.out.print("Student gender(M/F): ");	ptr.gender = keyboard.next();
		System.out.print("Student phone: ");		ptr.phone = keyboard.nextInt();
		System.out.print("Student address: ");		ptr.address = keyboard.next();
		System.out.println("");

		prev = head;
		current = head.next;
		while ((current != null) && (current.id >= ptr.id)) {
			prev = current;
			current = current.next;
		}
		ptr.next = current;
		prev.next = ptr;		
	}
/************************************************************************/
	public void delete_f(){
		System.out.println("Call delete_f().... \n");

		int del_id = 0;
		int count = 0;      

		if (head.next == null) {
			System.out.print("No student record\n\n");
		}
		else {
			System.out.print("Delete student ID: ");       
			del_id = keyboard.nextInt();

			prev = head;
			current = head.next;
			while ((current != null) && (!(del_id == current.id))) {
					prev = current;
					current = current.next;
			}

			if (current != null) {
				prev.next = current.next;
				current = null;
				System.out.printf("%s record is deleted\n\n", del_id);
			}
			else {
				System.out.printf("%s is not found\n\n", del_id);
			}
		}
	}
/************************************************************************/
	public void modify_f(){
	    System.out.println(" Call modify_f().... \n");
	    String modify_name;
	    int modify_score;
	    System.out.printf("Student name: ");
	    modify_name = keyboard.next();
	
	    prev = head;
	    current = head.next;
	    while((current != null) && !(current.name).equals(modify_name)) {
	        prev = current;
	        current = current.next;
	    }
	
	    if (current != null) {
	        System.out.printf("**************************\n");
	        System.out.printf("Original score: %d\n", current.score);
	        System.out.printf("**************************\n");
	        System.out.printf("New Score: ");
	        modify_score = keyboard.nextInt();
	        current.score = modify_score;
	        System.out.printf("Updated!\n\n");
	    }
	    else {
	        System.out.printf("%s is not found\n\n", modify_name);
	        return;
	    }

	    // 1. 指定 current 節點資料給 newNode
	    modifyNode = new Student();
	    modifyNode.name = current.name.substring(0);
	    modifyNode.score = current.score;
	
	    // 2. 刪除 current 節點
	    prev.next = current.next;
	    current = null;
	    
	    // 3. 再重新排序1
	    prev = head;
	    current = head.next;
	    while ((current != null) && (current.score > modifyNode.score)) {
	        prev = current;
	        current = current.next;
	    }
	    modifyNode.next = current;
	    prev.next = modifyNode;

}
/************************************************************************/
	public void display_f(){
		System.out.println("Call display_f().... \n");

		int count = 0;
	 	if (head.next == null) {
			System.out.print("No student record\n\n");
	 	}
		else {
			System.out.printf("%-15s %-15s %-15s %-15s %-15s\n", "ID", "NAME", "GENDER", "PHONE", "ADDRESS");

			for(int i=1; i<=25; i++) System.out.print("-"); System.out.printf("\n");

			current = head.next;
			while (current != null) {
				System.out.printf("%-15d", current.id);
				System.out.printf("%-17s", current.name);
				System.out.printf("%-17s", current.gender);
				System.out.printf("%-15d", current.phone);
				System.out.printf("%-17s", current.address);
				System.out.printf("\n");

				current = current.next;
				count++;
			}

			for(int i=1; i<=25; i++) System.out.print("-"); System.out.printf("\n");
			System.out.printf("Total %d record(s) found\n\n", count);
		}
	}
/************************************************************************/
	public static void main (String args[]){

		List obj = new List();
		int option=0;

		do {
			System.out.println("******  Single list operation *****");
			System.out.println("          <1> Insert			   ");
			System.out.println("          <2> Delete               ");
			System.out.println("          <3> modify               ");
			System.out.println("          <4> Display              ");			 
			System.out.println("          <5> Exit                 ");
			System.out.println("***********************************");
			System.out.print("     Please choose one: ");
			
	 	    try {
				option = keyboard.nextInt();
			} catch(InputMismatchException e) {
				keyboard.nextLine();
				System.out.printf("Not a correct number.\n");
				System.out.printf("Try again\n");
			}
			System.out.println("");
			switch (option) {			   
				case 1 :
					obj.insert_f(); // 新增函數
					break;
				case 2 :
					obj.delete_f(); // 刪除函數
					break;
          case 3 :
             obj.modify_f(); // 修改函數
					break;
				case 4 :
					obj.display_f();  // 輸出函數
					break;
				case 5 :
					System.exit(0);	
			}			
		} while (true);
	}
}
