void ChessConclient::updateScreen() {
	this->clearScreen();
	this->drawBoard();
	this->printMoveMessage();
}

void ChessConclient::clearScreen() {
	system("CLS");
}

void ChessConclient::drawBoard() {
	cout << BOARD_LITERAL_MAP << TABSPC + "Records Table" << endl;
	for (int j = BSIDE_N-1; j >= 0; j--) {
		for (int i = 0; i < BSIDE_N; i++) {
			if (i == 0) {
				cout << j + 1;
			}
			cout << (*(*this->engine).getBoardState())[j][i];
			if (i == BSIDE_N-1) {
				cout << j + 1;
				if (this->records[RECORDS_N-j-1] == EMPSTR) {
					cout << TABSPC << endl;
				} else {
					cout << TABSPC << this->records[RECORDS_N - j - 1] << endl;
				}
			}
		}
	}
	cout << BOARD_LITERAL_MAP << endl << endl;
}

void ChessConclient::printMoveMessage() {
	if ((*this->engine).getNextColor() == NEXT_COLOR_WHITE) {
		cout << WPLAYER_NAME << TURN_MSG << endl;
		return;
	}
	cout << BPLAYER_NAME << TURN_MSG << endl;
}

void ChessConclient::promptInfoMessage(string message) {
	cout << message << endl;
	cout << PRESS_ENTER_MSG;
	getchar();
}

void ChessConclient::promptErrorMessage(string message) {
	cout << "Error: " << message << endl;
	cout << PRESS_ENTER_MSG;
	getchar();
}

string ChessConclient::getPieceName(char piece) {
	if (piece == WPAWN) {
		return WPLAYER_NAME + WSPC + PAWN_NAME;
	}
	if (piece == WKNIGHT) {
		return WPLAYER_NAME + WSPC + KNIGHT_NAME;
	}
	if (piece == WBISHOP) {
		return WPLAYER_NAME + WSPC + BISHOP_NAME;
	}
	if (piece == WROOK) {
		return WPLAYER_NAME + WSPC + ROOK_NAME;
	}
	if (piece == WQUEEN) {
		return WPLAYER_NAME + WSPC + QUEEN_NAME;
	}
	if (piece == WKING) {
		return WPLAYER_NAME + WSPC + KING_NAME;
	}
	if (piece == BPAWN) {
		return BPLAYER_NAME + WSPC + PAWN_NAME;
	}
	if (piece == BKNIGHT) {
		return BPLAYER_NAME + WSPC + KNIGHT_NAME;
	}
	if (piece == BBISHOP) {
		return BPLAYER_NAME + WSPC + BISHOP_NAME;
	}
	if (piece == BROOK) {
		return BPLAYER_NAME + WSPC + ROOK_NAME;
	}
	if (piece == BQUEEN) {
		return BPLAYER_NAME + WSPC + QUEEN_NAME;
	}
	if (piece == BKING) {
		return BPLAYER_NAME + WSPC + KING_NAME;
	}
	return "error";
}
