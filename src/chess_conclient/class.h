class ChessConclient {
public:
	ChessConclient(ChessEngine* engine);
	void run();

private:
	ChessEngine* engine; // include <chess_engine/class.h>
	string input;
	string records[RECORDS_N];
	char inputStatus;
	int movesCount;

	void updateScreen();
	void clearScreen();
	void drawBoard();
	void printMoveMessage();

	void readInput();
	void processInput();
	bool isInputExit();
	bool isInputLengthValid();
	bool isInputMoveValid();
	void transformInputUppercase();
	void incrementMovesCount();

	void makeMove();
	
	void promptInfoMessage(string message);
	void promptErrorMessage(string message);

	string getRecordLine();
	void addNewRecord(string recordLine);
	string getPieceName(char piece);
};
