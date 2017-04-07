/*_______SHREY MANIK______*/
#include <iostream>
#include <string>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cstring>
#include <iomanip>
#include <list>
#include <bitset>
#include <ctime>
#define ff first
#define ss second
#define mod 1000000007
#define SET(a) memset(a,-1,sizeof(a))
#define CLEAR(a) memset(a,0,sizeof(a))
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define trace1(x)                cerr << #x << ": " << x << endl;

using namespace std;
typedef long long ll;
typedef pair< int , int > pii;
typedef pair< int , ll> pil;
typedef pair< ll, int>pli;
typedef pair< ll, ll> pll;
typedef vector< ll >vl;
typedef vector< int > vi;
ll gcd(ll a,ll b){return (b==0)?a:gcd(b,a%b);}
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}
ll powmod(ll a,ll b) {ll res=1;if(a>=mod)a%=mod;for(;b;b>>=1){if(b&1)res=res*a;if(res>=mod)res%=mod;a=a*a;if(a>=mod)a%=mod;}return res;}
void fast(){ ios_base::sync_with_stdio(false); cin.tie(0);}
void fileIO(){freopen("input.in","r",stdin);freopen("output1.txt","w",stdout);}

const int BIGMAXDEPTH = 20;
const int N = 11;
const int M = 11;
const int ALPHA = -100000;
const int BETA = 100000;
const int RANDOM = 605000;
const int MAXSCORE = 1000;
const int MINSCORE = -1000;
const int MINVALUE = -10000;
const int MAXVALUE = 10000;

char ID, CID;
bool vis[N][M];
bool TIMEOUT = false;
bool globalFlag = false;;
int MAXDEPTH;
int leftY, rightY, downX, upX, ansX, ansY, countDownX, countRightY;
int time1;
int neighbourX[] = {-1, -1, 0, 1, 1, 0};
int neighbourY[] = {0, 1, 1, 0, -1, -1};
int cflag = 0;


bool isValid(int x, int y) {
	if(x < 0 || x >= N || y < 0 || y >= M)
		return false;
	return true;
}

inline bool isBoundary(int x, int y) {
	if(x == 0 || x == N - 1 || y == 0 || y == M - 1)
		return true;
	return false;
}

char opposite(char id) {
	if(id == 'R')
		return 'B';
	else 
		return 'R';
}

bool compe(const vector < int >& a, const vector < int >& b) {
	const int K = 2;
	const int R = 3;
	int x = a[K];
	int y = b[K];
	int f = a[R];
	int g = b[R];
	//return a[R] < b[R];
	return x > y;
	//if(x > y || ((x == y) && (f == g)))
		//return true;
	//else 
	//	return false;
	//return true;
	/*
	if(a[K] > b[K])
		return true;
	else if(a[K] < b[K])
		return false;
	else if(a[K] == b[K]) {
		if(a[R] <= b[R])
			return true;
		else return false;
	}
	
	return true;
	*/
} 

pii countNeighbour(vector < vector< char > > board, int x, int y, char id) {
	int countID, countCID;
	countID = 0, countCID = 0;
	for(int i = 0; i < 6; ++i) {
		int nx = x + neighbourX[i];
		int ny = y + neighbourY[i];
		if(isValid(nx, ny)) {
			if(board[nx][ny] == id)
				countID++;
			else if(board[nx][ny] == opposite(id))
				countCID++;
		}
	}
	return mp(countID, countCID);
}

vector < pii > getAvailableMoves(vector < vector< char > > board, char id) {
	
	vector < int > order;
	vector < vector < int >  > orderMoves;
	vector < pii > moves;
	//trace1(id);
	if(id == 'R') {
		for(int j = 0 ; j < M; j++) {
			for(int i = N - 1; i >= 0; i--) {
				order.clear();
				if(board[i][j] == 'U') {
					moves.pb(mp(i,j));
					/*
					order.pb(i);
					order.pb(j);
					pii p = countNeighbour(board, i, j, id);
					order.pb(p.ff);
					order.pb(p.ss);
					orderMoves.pb(order);
					*/
					//cout<<order.size();
				}
			}
		}
	}
	else if(id == 'B') {
		for(int j =  M - 1; j >= 0; j--) {
			for(int i = 0; i < N; i++) {
				order.clear();
				if(board[i][j] == 'U') {
					moves.pb(mp(i,j));
					/*
					order.pb(i);
					order.pb(j);
					pii p = countNeighbour(board, i, j, id);
					order.pb(p.ff);
					order.pb(p.ss);
					orderMoves.pb(order);
					*/
					//cout<<order.size();
				}
			}
		}
	}
	
	//cout<<orderMoves.size();
	//sort(orderMoves.begin(), orderMoves.end(), compe);
	//for(int i = 0; i < orderMoves.size(); ++i) {
	//	moves.pb(mp(orderMoves[i][0], orderMoves[i][1]));
		//cout<<orderMoves[i][2] << " " << orderMoves[i][3];
	//}
	//cout<<endl;
	/*
	for(int i=0;i<moves.size();i++) {
		cout<<moves[i].ff << moves[i].ss << " ";
	}
	cout<<endl;
	*/
	//cout<<moves.size();
	return moves;
}

void dfs(vector < vector< char > > board, int x, int y, char id) {
	
	upX = min(upX, x);
	if(x == downX) {
		countDownX++;
	}
	else if(x > downX) {
		countDownX = 1;
		downX = x;
	}
	leftY = min(leftY, y);
	if(y == rightY) {
		countRightY++;
	}
	else if(y > rightY) {
		countRightY = 1;
		rightY = y;
	}
	vis[x][y] = true;
	for(int i = 0; i < 6; ++i) {
		int nx = x + neighbourX[i];
		int ny = y + neighbourY[i];
		if(isValid(nx, ny) && !vis[nx][ny] && board[nx][ny] == id) {
			dfs(board, nx, ny, id);
		}
	}
	
}
	

int score(vector < vector< char > > board) {
	
	int horizontalLenID = 0;
	int verticalLenID = 0;
	int horizontalLenCID = 0;
	int verticalLenCID = 0;
	int countID = 0;
	int countCID = 0;
	int hLen,vLen;
	int hLenMaxID = 0;
	int vLenMaxID = 0;
	int hLenMaxCID = 0;
	int vLenMaxCID = 0;
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < M; ++j) {
			vis[i][j] = false;
		}
	}
	
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < M; ++j) {
			if(isBoundary(i, j)) {
				if(board[i][j] == ID)
					countID++;
				else if(board[i][j] == CID)
					countCID++;
			}
			if(!vis[i][j] && board[i][j]!= 'U') {
				leftY = M;
				rightY = -1;
				upX = N;
				downX = -1;
				countRightY = 0;
				//countUY = 0;
				countDownX = 0;
				dfs(board, i, j, board[i][j]);
				if(board[i][j] == ID) {
					// Check FLAG
					cflag = 1;
					hLen = rightY - leftY + 1;
					vLen = downX - upX + 1;
					if(horizontalLenID == hLen) {
						hLenMaxID += countRightY;
					}
					else if(horizontalLenID < hLen) {
						horizontalLenID = hLen;
						hLenMaxID = countRightY;
					}
					if(verticalLenID == vLen) {
						vLenMaxID += countDownX;
					}
					else if(verticalLenID < vLen) {
						verticalLenID = vLen;
						vLenMaxID = countDownX;
					}	
				}
				else {
					hLen = rightY - leftY + 1;
					vLen = downX - upX + 1;
					if(horizontalLenCID == hLen) {
						hLenMaxCID += countRightY;
					}
					else if(horizontalLenCID < hLen) {
						horizontalLenCID = hLen;
						hLenMaxCID = countRightY;
					}
					if(verticalLenCID == vLen) {
						vLenMaxCID += countDownX;
					}
					else if(verticalLenCID < vLen) {
						verticalLenCID = vLen;
						vLenMaxCID = countDownX;
					}
				}
				
			}
		}
	}
	int maxLenID; 
	int maxLenCID;
	int value;
	if(ID == 'R') {
		maxLenID = horizontalLenID;
		maxLenCID = verticalLenCID;
		/*
		if(maxLenID > maxLenCID && maxLenID > 7)
			maxLenID *= 2;
		else if(maxLenID < maxLenCID && maxLenCID > 7)
			maxLenCID *= 2;
		*/
		value = 5*(maxLenID - maxLenCID) + (hLenMaxID - vLenMaxCID);
	}
	else {
		maxLenID = verticalLenID;
		maxLenCID = horizontalLenCID;
		/*
		if(maxLenID > maxLenCID && maxLenID > 7)
			maxLenID *= 2;
		else if(maxLenID < maxLenCID && maxLenCID > 7)
			maxLenCID *= 2;		
		*/
		value = 5*(maxLenID - maxLenCID) + (vLenMaxID - hLenMaxCID);
	}
	// Checking Maxlengths
	//cout<<maxLenID<<"\n";
	//cout<<maxLenCID<<"\n";
	//trace1(cflag);
	if(maxLenID == N)
		return MAXSCORE;
	if(maxLenCID == N)
		return MINSCORE;	
	return (value);
	//(maxLenID - maxLenCID);
	// + (countID - countCID);
}

int minimax(vector < vector< char > > board, char id, int depth, int alpha, int beta) {
	 
	 int time3 = clock();
	 if((float)(time3 - time1) / CLOCKS_PER_SEC >= 4.90) {
		TIMEOUT = true;
		return -100000;
	 }
	 //cout<<"HDH";
	 int terminal = score(board);
	 if(depth == 0)
		return terminal;
	// if(terminal == MAXSCORE || terminal == - MAXSCORE) {
		//return terminal;
	//}
	 int ans = MINVALUE, lowAns = MAXVALUE;
	 bool isAvailable = false;
	//ool flag = false;
	 vector < pii > moves = getAvailableMoves(board, id);
	 for(int i = 0; i < moves.size(); ++i) {
		 int x = moves[i].ff;
		 int y = moves[i].ss;
		 isAvailable = true;
		 if(globalFlag == 0 && depth == MAXDEPTH) {
			 ansX = x;
			 ansY = y;
			 globalFlag = true;
			 if(terminal == MAXSCORE || terminal == MINSCORE) {
				return terminal;
			}
		 }
		 board[x][y] = id;
		 int val = minimax(board, opposite(id), depth - 1, alpha, beta);
		 //if(depth == MAXDEPTH)
		//	cout << val << "  " ;
		 if(val > ans) {
			 ans = val;
			 if(depth == MAXDEPTH) {
				 ansX = x;
				 ansY = y;
			 }
		 }
		 lowAns = min(lowAns, val);
		 board[x][y] = 'U';
		 if(TIMEOUT == true) {
			return -10000;
		}
		 if(id == ID) {
			 alpha = max(alpha, ans);
			 if(alpha >= beta) {
				//cout << ans; // Testing
				return ans;
			}
		}
		if(id == CID) {
			beta = min(beta, lowAns);
			if(alpha >= beta) {
				//cout << lowAns; //Testing
				return lowAns;
			}
		}
	}
	
	if(!isAvailable)
		return score(board);
	if(id == ID) {
		//cout << ans; //Testing
		return ans;
	}
	else {
		//cout << lowAns; //Testing
		return lowAns;
	}
	
}

void iterativeDeepening(vector < vector< char > > board, char id) {
	int time2;
	float tx;
	int val, x, y, answer = -1000000;
	for(int i = 1; i <= BIGMAXDEPTH; ++i) {
		MAXDEPTH = i;
		time2 = clock();
		tx = (float)(time2 - time1) / CLOCKS_PER_SEC;
		//trace1(tx);
		//if(tx < 2.00f)
		val = minimax(board, id, i, ALPHA, BETA);
		//else break;
		if(val == MAXSCORE)
			return;
		if(TIMEOUT == true) {
			if(answer >= val) {
				ansX = x;
				ansY = y;
			}
			return;
		}
		else {
			answer = val;
			x = ansX;
			y = ansY;
		}			

	}
}
		

//Testing Functions

void printBoard(vector < vector< char > > board) {
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < M; ++j) {
			//board[i][j] = 'U';
			cout<<board[i][j]<<" ";
		}
		cout<<"\n";
	}
}

int isGameOver(vector < vector< char > > board) {
	int c = score(board);
	if(c == MAXSCORE)
		return 1;
	if(c == - MAXSCORE)
		return 2;
	return 0;
}

int main() 
{	
	//fast();
	vector<vector<char> > board(N, vector<char>(M));
	char color;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}
	cin >> color;
	//change for player 2
	ID = 'R';
	CID = 'B';
	time1 = clock();
	//trace1(color);
	/* CHECK HERE
	if(color == 'R') {
		ID = 'R';
		CID = 'B';
	}
	else {
		ID = 'B';
		CID = 'R';
	}
	*/
	//cout << score(board) << "\n";
	iterativeDeepening(board, ID);
	//MAXDEPTH = 3; //CHANGE HERE
	//minimax(board, ID, MAXDEPTH, ALPHA, BETA);
	cout << ansX << ' ' << ansY << "\n";
	
	/*
	 *  Testing Section
	 * 
	 * 
	 *
	 *
	ID = 'B';
	CID = 'R';
	cout<<"sdsdg";
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < M; ++j) {
			if(i == 0 && j == 0)board[i][j] = 'R';
			else
				board[i][j] = 'U';
			cout<<board[i][j]<<" ";
		}
		cout<<"\n";
	}
	int x, y;
	while(1){
		//ccout << score(board) << "\n";
		//flag = false;
		//cout<<"HDH";
		
		minimax(board, 'B', MAXDEPTH, ALPHA, BETA);		
		cout << ansX << ' ' << ansY << "\n";
		board[ansX][ansY] = 'B';
		printBoard(board);
		cin >> x >> y;
		board[x][y] = 'R';
		printBoard(board);
		int c = isGameOver(board);
		if(c == 1) {
			cout<<"P1 wins";
			break;
		}
		else if(c == 2) {
			cout<<"P2 wins";
			break;
		}
	}
	*/
	return 0;
}
