ChessConclient::ChessConclient(ChessEngine* engine) {
	this->engine = engine;
}

void ChessConclient::run() {
	(*this->engine).startNewGame();

	while (true) {
		this->updateScreen();

		this->incrementMovesCount();
		this->readInput();
		this->processInput();

		if (this->inputStatus == INPUT_STATUS_EXIT) {
			this->promptInfoMessage("Have a nice day! :)");
			break;
		} else if (this->inputStatus == INPUT_STATUS_INVALID) {
			this->promptErrorMessage("entered invalid command.\n" \
									 "Try moves like: 'e2e4' or 'e7e5'.\n" \
									 "Type 'q', 'quit' or 'exit' for quit");
			continue;
		}

		this->makeMove();

		if ((*this->engine).getGameStatus() == GAME_STATUS_BAD_MOVE) {
			this->promptErrorMessage("unavailable move");
			continue;
		}

		string recordLine = to_string(this->movesCount) + WSPC + input + WSPC + this->getRecordLine();
		
		this->addNewRecord(recordLine);
	}
}

void ChessConclient::incrementMovesCount() {
	this->movesCount++;
}

void ChessConclient::makeMove() {
	char i1 = this->input[0] - ZERO_BACK_SHIFT;
	char j1 = this->input[1];
	char i2 = this->input[2] - ZERO_BACK_SHIFT;
	char j2 = this->input[3];

	cout << i1 << endl;
	cout << j1 << endl;
	cout << i2 << endl;
	cout << j2 << endl;

	(*this->engine).makeMove(i1, j1, i2, j2);
}

string ChessConclient::getRecordLine()  {
	char id1 = (*this->engine).getPieceID1();
	char id2 = (*this->engine).getPieceID2();

	if (id1 == NOPIECE) {
		return this->getPieceName(id1) + " moves";
	}

	return this->getPieceName(id1) + " takes " + this->getPieceName(id2);
}

void ChessConclient::addNewRecord(string recordLine) {
	bool isArrayFull = true;

	for (int i = 0; i < RECORDS_N; i++) {
		if (this->records[i] == EMPSTR) {
			isArrayFull = false;
			break;
		}
	}

	if (isArrayFull) {
		for (int i = 1; i < RECORDS_N; i++) {
			this->records[i-1] = this->records[i];
		}
		this->records[RECORDS_N-1] = recordLine;
		return;
	}

	for (int i = 0; i < RECORDS_N; i++) {
		if (this->records[i] == EMPSTR) {
			this->records[i] = recordLine;
			break;
		}
	}
}
