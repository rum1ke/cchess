class ChessEngine {
public:
	void startNewGame();
	void makeNewMove(int moveCode);
	char getGameStatus();
	bool getNextColor();
	int getPieceID1();
	int getPieceID2();

	typedef char char2D[BSIDE_N][BSIDE_N];
	char2D* getBoardState();

private:
	char board[BSIDE_N][BSIDE_N];
	char gameStatus;
	bool nextColor;
	char id1;
	char id2;
	char i1;
	char j1;
	char i2;
	char j2;

	void arrangePieces();
	bool isMoveAvailable();
	void movePiece();
	bool isPieceEquals(int nVariants, char variantOne, ...);
	bool isCanMoveWPawn();
	bool isCanMoveBPawn();
};
