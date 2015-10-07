#include <iostream> 
#include <string> 
using namespace std; 

int main (void) { 
	ios::sync_with_stdio(false); cin.tie(0);
	int n, a, b; 
	string command, place; 
	int posa[2]; 
	int posb[2]; 
 	 
 	cin >> n; 
 	 
 	int tbl[n][n]; 
 	 
 	for (int i = 0; i < n; i++) 
 		for (int j = 0; j < n; j++) 
 			tbl[i][j] = -1; 
 		 
 	for (int i = 0; i < n; i++) 
 		tbl[i][0] = i; 
 	 
 	while (cin >> command) { 
 		if (command == "quit") 
 			break; 
 		 
 		cin >> a >> place >> b; 
 		 
 		if (a == b) continue; 
 		 
 		for (int i = 0; i < n; i++) { 
 			for (int j = 0; j < n; j++) { 
 				if (tbl[i][j] == a) { 
 					posa[0] = i; 
 					posa[1] = j; 
 				} 
 				if (tbl[i][j] == b) { 
 					posb[0] = i; 
 					posb[1] = j; 
 				} 
 			} 
 		} 
 		 
 		if (posa[0] == posb[0]) continue; 
 		 
 		if (command == "move") { 
 			if (place == "onto") { 
 				for (int i = 0; i < n; i++) { 
 					for (int j = 0; j < n; j++) { 
 						if (tbl[i][j] == a || tbl[i][j] == b) { 
 							for (int y = j + 1; y < n; y++) { 
 								if (tbl[i][y] == -1) break; 
 								tbl[tbl[i][y]][0] = tbl[i][y]; 
 								tbl[i][y] = -1; 
 							} 
 						} 
 					} 
 				} 
 				 
 				bool found = false; 
 				 
 				for (int i = 0; i < n; i++) { 
 					for (int j = 0; j < n; j++) { 
 						if (tbl[i][j] == b) { 
 							posb[0] = i; 
 							posb[1] = j + 1; 
 							found = true; 
 							break; 
 						} 
 					} 
 					if(found) break; 
 				} 
 				 
 				bool moved = false; 
 				 
 				for (int i = 0; i < n; i++) { 
 					for (int j = 0; j < n; j++) { 
 						if (tbl[i][j] == a) { 
 					
 							tbl[i][j] = -1; 
 						
 							tbl[posb[0]][posb[1]] = a; 
 							break; 
 						} 
 					} 
 					if (moved) break; 
 				} 
 			} else if (place == "over") { 
 				for (int i = 0; i < n; i++) { 
 					for (int j = 0; j < n; j++) { 
 						if (tbl[i][j] == a ) { 
							posa[0] = i; 
 							posa[1] = j; 
 							for (int y = j + 1; y < n; y++) { 
 								if (tbl[i][y] == -1) break; 
 								tbl[tbl[i][y]][0] = tbl[i][y]; 
 								tbl[i][y] = -1; 
 							} 
 						} 
 					} 
 				} 
 				 
 				bool found = false; 
 				  
 				for (int i = 0; i < n; i++) { 
 					for (int j = 0; j < n; j++) { 
 						if (tbl[i][j] == b) { 
							found = true; 
 						} 
 						if (tbl[i][j] == -1) { 
 							if (found) { 
 								posb[0] = i; 
 								posb[1] = j; 
 							} 
 							break; 
 						} 
 					} 
 					if (found) break; 
 				} 
 				 
 			 
 				tbl[posa[0]][posa[1]] = -1; 
  
 				tbl[posb[0]][posb[1]] = a; 
 			} 
 		} else if (command == "pile") { 
 			if (place == "onto") { 
 				bool found = false;  
 				for (int i = 0; i < n; i++) { 
 					for (int j = 0; j < n; j++) { 
 						if (tbl[i][j] == -1) break; 
 						if (tbl[i][j] == b) { 
 							posb[0] = i; 
 							posb[1] = j + 1; 
 							 
 							found = true; 
 							 
 							for (int y = j + 1; y < n; y++) { 
 								if (tbl[i][y] == -1) break; 
 								tbl[tbl[i][y]][0] = tbl[i][y]; 
 								tbl[i][y] = -1; 
 							} 
 							break; 
 						} 
 					} 
 					if (found) break; 
 				} 
 				 
 				found = false; 
  				for (int i = 0; i < n; i++) { 
 					for (int j = 0; j < n; j++) { 
 						if (tbl[i][j] == a) { 
 							found = true; 
 							posa[0] = i; 
 							posa[1] = j; 
 							break; 
 						} 
 					} 
 					if (found) break; 
 				} 
 				 
 				for (int i = posa[1]; i < n; i++) { 
 					if (tbl[posa[0]][i] == -1) break; 
 					 
					tbl[posb[0]][posb[1]] = tbl[posa[0]][i]; 
 					tbl[posa[0]][i] = -1; 
 					 
 					posb[1]++; 
 				} 
 			} else if (place == "over") { 
 				bool found = false; 
 				for (int i = 0; i < n; i++) { 
 					for (int j = 0; j < n; j++) { 
 						if (tbl[i][j] == -1) break; 
 						 
 						if (tbl[i][j] == a) { 
 							posa[0] = i; 
 							posa[1] = j; 
 							found = true; 
 							break; 
 						} 
 					} 
 					if (found) break; 
 				} 
 				 
 				found = false; 
 				// searching for b 
 				for (int i = 0; i < n; i++) { 
 					for (int j = 0; j < n; j++) { 
 						if (tbl[i][j] == -1) break; 
 						 
 						if (tbl[i][j] == b) { 
 							for (int y = j + 1; y < n; y++) { 
 								if (tbl[i][y] == -1) { 
 									posb[0] = i; 
 									posb[1] = y; 
 									break; 
 								} 
 							} 
 							found = true; 
 							break; 
 						} 
 					} 
 					if (found) break; 
 				} 
 				for (int i = posa[1]; i < n; i++) { 
 					if (tbl[posa[0]][i] == -1) break; 
 					 
 					tbl[posb[0]][posb[1]] = tbl[posa[0]][i]; 
 					tbl[posa[0]][i] = -1; 
 					 
 					posb[1]++; 
 				} 
 			} 
 		} 
 	} 
 	for (int i = 0; i < n; i++) { 
 		cout << i << ":"; 
 		for (int j = 0; j < n; j++) { 
 			if (tbl[i][j] == -1) break; 
 			cout << " " << tbl[i][j]; 
 		} 
 		cout << endl; 
 	} 
 	 
 	return 0; 
 } 
