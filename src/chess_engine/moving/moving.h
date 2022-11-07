void ChessEngine::makeNewMove(int moveCode) {
	this->i1 = moveCode % 10000 / 1000;
	this->j1 = moveCode % 1000 / 100;
	this->i2 = moveCode % 100 / 10;
	this->j2 = moveCode % 10;
	this->id1 = this->board[this->j1][this->i1];
	this->id2 = this->board[this->j2][this->i2];

	if (this->isMoveAvailable()) {
		this->movePiece();
		this->nextColor = !this->nextColor;
		this->gameStatus = GAME_STATUS_READY;
	}

		return;
	}

	this->gameStatus = GAME_STATUS_BAD_MOVE;
}

bool ChessEngine::isMoveAvailable() {
	if (this->nextColor == NEXT_COLOR_WHITE) {
		if (this->board[this->j1][this->i1] == WPAWN) {
			if (this->isCanMoveWPawn()) {
				return true;
			}
		}
	} else {
		if (this->board[this->j1][this->i1] == BPAWN) {
			if (this->isCanMoveBPawn()) {
				return true;
			}
		}
	}
	return false;
}

void ChessEngine::movePiece() {
	this->board[this->j2][this->i2] = this->id1;
	this->board[this->j1][this->i1] = NOPIECE;
}

bool ChessEngine::isPieceEquals(int nVariants, char variantOne, ...) {
	char *ptr = &variantOne;

	while (nVariants--) {
		if (this->board[this->j2][this->i2] == *ptr) {
			return true;
		}
	}
	return false;
}
