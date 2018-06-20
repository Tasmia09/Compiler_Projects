/*
 * Tasmia Rahman, COSC461, Assignment 1 
 */

import java.util.List;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.Iterator;


public class NFA2DFA {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static Scanner sc = new Scanner(System.in);
	static BufferedReader bufRead;
	static FileReader input;
	
	static List<Integer> finalStateList = new ArrayList<Integer>();
	static int initialStateNum = 0;
	static int totalState;
	
	static List<String> inputSymbolList = new ArrayList<String>();
	static ArrayList<State> nextStateList;	
	static HashMap<String,ArrayList<State>> nextStateMap;
	static List<HashMap<String,ArrayList<State>>> listOfMaps;
	static State [] stateArray;
	
	static int stateNum;
	static boolean finalState;
	static boolean initialState;	
	static int stateCount=0;
	
	
	
	//variables for DFA
	static int newDFAStateCount = 1;
	static List<State> newDFAStateList = new ArrayList<State>();
	static HashMap<String,State> nextDFAStateMap;
	static List<HashMap<String,State>> listOfDFAMaps;
	static List<List<State>> allStateAsDFA = new ArrayList<List<State>>();
	static int DFAStateCount = 0;
	static int uniqueCount = 0;
	static List<Integer> finalDFAStateList = new ArrayList<Integer>();
	static String s;
		
	public static void main(String[] args){
		// TODO Auto-generated method stub
		if(args.length>0){
			s = args[0];
		}
		else{
			//if no file is entered
			s="input3.txt";
		}
			openFile();
			try{
				readFile();
			}catch(Exception e){
				System.out.println(e);
			}
			
			State inititialState = stateArray[initialStateNum-1];
			
			Nfa2Dfa(inititialState);
			DFAfinalList();
			
			//Printing the DFA
			printDFA();
			
			
		}
	
	//after constructing the DFA it will generate the Final States
	public static void DFAfinalList(){
		
		for(int index = 0;index<allStateAsDFA.size();index++){
			List<State>s = allStateAsDFA.get(index);
			for(State s1: s){
				
				if(s1.finalState == true){
					
					newDFAStateList.get(index).finalState = true;
					finalDFAStateList.add(index+1);
					break;
				}
				
			}
		}
		
	}
	
public static void Nfa2Dfa(State s){
		
		Queue<List<State>> st = new LinkedList <List<State>>();
		
		List<State> E_List = new ArrayList<State>();
		
		int check=0;
		
		//Adding initial state to a list that will be sent to E_Closure
		E_List.add(s);
		
		//adding the first state to queue
		List<State> unMarkDFA = E_Closure(E_List);
		st.add(unMarkDFA);
		
		
		//creating the first DFA state
		State s1 = new State(newDFAStateCount++);
		s1.initialState = true;
		newDFAStateList.add(s1);
		allStateAsDFA.add(unMarkDFA);
		
		while(!st.isEmpty()){
			
			listOfDFAMaps = new ArrayList<HashMap<String,State>>();
			List<State> markDFA = st.remove();
			
				// for each symbol list -> find edges -> find the E_Closure of the edges					
				for(int i = 0; i<inputSymbolList.size()-1;i++){
					uniqueCount=0;
					nextDFAStateMap = new HashMap<String,State>();
					
					
					List<State> moveSymbolList = E_Closure(findConnection(markDFA,inputSymbolList.get(i),i));
					
					//CHecking if the returned E_Closure list is unique or not
					if(moveSymbolList.size()>0)
					{
						for(List<State> stateList: allStateAsDFA){					
						
						if(stateList!=null){					
							if(stateList.containsAll(moveSymbolList) && stateList.size()==moveSymbolList.size()){	
								
								check =0;
								break;
						
							}
							else{
								uniqueCount++;
								check = 1;
								
							}
					
						}
					}
				}
					else{
						check =3;
					}
					
					//creating the new DFA State and pushing it into queue
					if(check==1){
						
						State s2 = new State(newDFAStateCount++);
						newDFAStateList.add(s2);
						nextDFAStateMap.put(inputSymbolList.get(i),s2);
						listOfDFAMaps.add(nextDFAStateMap);
						allStateAsDFA.add(moveSymbolList);
						st.add(moveSymbolList);
						
					}
					//when the vertex is null
					else if(check == 3){
						nextDFAStateMap.put(inputSymbolList.get(i),null);
						listOfDFAMaps.add(nextDFAStateMap);
					}
					//When the DFA already exists
					else{
						
						State s3 = newDFAStateList.get(uniqueCount);
						nextDFAStateMap.put(inputSymbolList.get(i),s3);
						listOfDFAMaps.add(nextDFAStateMap);
					}
				}
				//setting the value of list which has the hashmap of the edges with each input symbol to each DFA state 
				newDFAStateList.get(DFAStateCount++).setValues1(listOfDFAMaps);
			}
		}

//Find the edges for input symbol of each DFA state
public static List<State> findConnection(List<State>unMarkDFA,String inputSymbol, int indexOfSymbol){
	
	List<State> transList = new ArrayList<State>();
	
	Iterator<State> it = unMarkDFA.iterator();
	
	
	while(it.hasNext()){
		List<State> tempList = it.next().listOfMaps.get(indexOfSymbol).get(inputSymbol);
		if(tempList!=null){
			
			if( Collections.disjoint(tempList,transList)){
				
				transList.addAll(tempList);
				
			}
			else{				
				
				for(State s4 : tempList){
					if(!transList.contains(s4)){
						transList.add(s4);
						
					}
						
				}
				
			}			
			
		}
		
	}
	return transList;
}


//find the E_Closure of each state
public static List<State> E_Closure(List<State> findEStates){
	
	List <State> E_ClosureList = new ArrayList<State>();
	Stack<State> st = new Stack<State>();
	
	E_ClosureList.addAll(findEStates);
	st.addAll(E_ClosureList);

	
	while(!st.empty()){
		//System.out.println(st.size());
		State s = st.pop();
		//System.out.println(s.stateNum);
			List<State> tempList = s.listOfMaps.get(inputSymbolList.size()-1).
					get(inputSymbolList.get(inputSymbolList.size()-1));		
			
			if(tempList!=null && E_ClosureList!=null){
			
			if( Collections.disjoint(tempList,E_ClosureList)){
				//System.out.println("Unique");
				E_ClosureList.addAll(tempList);
				st.addAll(tempList);
			}
			else{				
				//System.out.println("No Unique");
				for(State s4 : tempList){
					if(!E_ClosureList.contains(s4)){
						E_ClosureList.add(s4);
						st.push(s4);
					}
						
				}
				
			}			
			
		}			
		
	}
	
	return E_ClosureList;
		
}

//opening the file from standard input	
public static void openFile(){
		try{
			input = new FileReader(s);
			bufRead = new BufferedReader(input);
		}catch(Exception e){
			System.out.println("File not found");
		}
		
}
	
//reading the file and constructing the NFA	
public static void readFile() throws IOException{	
		int countLine=0;
		String myLine = null;
		String[] array = null;
		
		while((myLine = bufRead.readLine()) != null){
			if(countLine<3){
				array = myLine.split(":");
				array[1] = array[1].trim();
				
				if(countLine == 0){
					try{
						
						initialStateNum = Integer.parseInt(array[1]);
					}catch(Exception e){
						System.out.println(e);
					}
				}
				else if(countLine == 1){
					StringTokenizer multiTokenizer = new StringTokenizer(array[1], "{,}");
					while (multiTokenizer.hasMoreTokens())
					{
					    String s = multiTokenizer.nextToken();
					    finalStateList.add(Integer.parseInt(s));
					}
					
				}
				else if(countLine == 2){
					
					totalState = Integer.parseInt(array[1]);					
					
					//Creating the array of all the states					
					stateArray = new State [totalState];
					
					//Setting the integer numbers of the states
					for(int x = 0;x<totalState;x++){
						stateArray[x]=new State(x+1);
						stateNum = x+1;
					}
					
					//marking the final states
					for(int x:finalStateList)
						stateArray[x-1].finalState = true;
					
					//marking the initial states
					stateArray[initialStateNum].initialState = true;
					
					
					
				}			
				
			}
			else{
				/*
				 * What does that \s+ mean?
				 * \s+ is a regular expression. 
				 * \s matches a space, tab, new line, carriage return, 
				 * form feed or vertical tab, and + says "one or more of those". 
				 * Thus the above code will collapse all "whitespace substrings" longer than one character, 
				 * with a single space character.
				 */
				
				
				String s = myLine.replaceAll("\\s+"," ");
				array = s.split(" ");
							
				if(countLine == 3){
					
					for(int c = 1; c<array.length; c++){						
							inputSymbolList.add(array[c]);
												
					}
					
				}
				
				else if(countLine >= 4 && stateCount< totalState){
					
					listOfMaps = new ArrayList<HashMap<String,ArrayList<State>>>();	
					
					
					for(int i = 0; i<inputSymbolList.size();i++){
						nextStateMap = new HashMap<String,ArrayList<State>>();
						nextStateList = new ArrayList<State>();
						
						StringTokenizer multiTokenizer = new StringTokenizer(array[i+1], "{,}");
						if(!multiTokenizer.hasMoreTokens()){
							nextStateList = null;
							
						}
						while (multiTokenizer.hasMoreTokens())
						{
						    String s1 = multiTokenizer.nextToken();					    
						    nextStateList.add(stateArray[Integer.parseInt(s1)-1]);
						}
						nextStateMap.put(inputSymbolList.get(i), nextStateList);
						listOfMaps.add(nextStateMap);
					}
					stateArray[stateCount++].setValues(listOfMaps);
					
				}
			}
			
			countLine++;
		}
	}


	public static void printDFA(){
		int stateInd = 1;
		System.out.println("reading NFA ... done.\n");
		System.out.println("creating corresponding DFA ...");
		
		for(List<State> s : allStateAsDFA){
			int commaCheck=0;
			System.out.print("new DFA state:\t"+stateInd++);
			
			if(stateInd-1<10)
				System.out.print("    -->  ");
			else if(stateInd-1>=10 && stateInd-1<=99)
				System.out.print("   -->  ");
			else if(stateInd-1>99 && stateInd-1<=999)
				System.out.print("  -->  ");
			
			List<Integer> list1 = new ArrayList<Integer>(); 
			for(State s3: s) 
				list1.add(s3.stateNum); 
			Collections.sort(list1); 
			System.out.print("{");
			for(int s4: list1){
				
				if(commaCheck == 0){
					System.out.print(s4);
					commaCheck = 1;
				}
				else
					System.out.print(","+s4);
			}
			 
			System.out.print("}");
			System.out.println();
		}
		System.out.println("done.\n");
		System.out.println("final DFA:");
		
		System.out.printf("Initial State:\t%d\n", newDFAStateList.get(0).stateNum);
		
		//Printing final State
				System.out.printf("Final States: \t{");
				Iterator<Integer> it1 = finalDFAStateList.iterator();
				if (it1.hasNext()) {
				    System.out.print(it1.next());
				}
				while (it1.hasNext()) {
				    System.out.print("," + it1.next());
				}
				System.out.print("}\n");
				
			//Printing total State
			System.out.printf("Total STates:\t%d\n",newDFAStateList.size());
				
		
		//Printing the header of the list
				System.out.printf("State\t");
				for(int x = 0; x<inputSymbolList.size()-1; x++)
					System.out.printf("%s\t\t",inputSymbolList.get(x));
				System.out.println();
				
		for(State it:newDFAStateList){
			System.out.printf("%d\t",it.stateNum);
			for(int i = 0; i<inputSymbolList.size()-1; i++){
				State s = it.listOfDFAMaps.get(i).get(inputSymbolList.get(i));
				if(s == null){
					System.out.print("{}\t\t");
					}
				else{
				System.out.print("{");
				System.out.print(s.stateNum);
				
				System.out.printf("}\t\t");
				}
			}
			System.out.println();
		}
	}
}

class State{
	int stateNum;
	State state;
	boolean initialState;
	boolean finalState;
	int totalState;
	String inputSymbol;
	List<HashMap<String,ArrayList<State>>> listOfMaps;
	List<HashMap<String,State>> listOfDFAMaps;

	State(int stateNum){
		this.stateNum = stateNum;
	}
	
	public void setValues(List<HashMap<String,ArrayList<State>>> listOfMaps){
		this.listOfMaps = listOfMaps;
	}
	
	public void setValues1(List<HashMap<String,State>> listOfMaps){
		this.listOfDFAMaps = listOfMaps;
	}
	
}