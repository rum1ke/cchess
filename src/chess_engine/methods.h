void ChessEngine::startNewGame() {
	this->arrangePieces();
	this->gameStatus = GAME_STATUS_READY;
	this->nextColor = NEXT_COLOR_WHITE;
}

void ChessEngine::arrangePieces() {
	this->board[7][0] = BROOK;
	this->board[7][1] = BKNIGHT;
	this->board[7][2] = BBISHOP;
	this->board[7][3] = BQUEEN;
	this->board[7][4] = BKING;
	this->board[7][5] = BBISHOP;
	this->board[7][6] = BKNIGHT;
	this->board[7][7] = BROOK;

	for (int i = 0; i < BSIDE_N; i++) {
		this->board[6][i] = BPAWN;
	}

	for (int i = 0; i < BSIDE_N; i++) {
		for (int j = 2; j < BSIDE_N - 2; j++) {
			this->board[j][i] = NOPIECE;
		}
	}

	for (int i = 0; i < BSIDE_N; i++) {
		this->board[1][i] = WPAWN;
	}

	this->board[0][0] = WROOK;
	this->board[0][1] = WKNIGHT;
	this->board[0][2] = WBISHOP;
	this->board[0][3] = WQUEEN;
	this->board[0][4] = WKING;
	this->board[0][5] = WBISHOP;
	this->board[0][6] = WKNIGHT;
	this->board[0][7] = WROOK;
}

char ChessEngine::getGameStatus() {
	return this->gameStatus;
}

bool ChessEngine::getNextColor() {
	return this->nextColor;
}

char ChessEngine::getPieceID1() {
	return this->id1;
}

char ChessEngine::getPieceID2() {
	return this->id2;
}

typedef char char2D[BSIDE_N][BSIDE_N];
char2D* ChessEngine::getBoardState() {
	return &this->board;
}
