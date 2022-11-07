void ChessConclient::readInput() {
	cin >> this->input;
	getchar();
}

void ChessConclient::processInput() {
	if (this->isInputExit()) {
		this->inputStatus = INPUT_STATUS_EXIT;
		return;
	}
	
	if (!this->isInputLengthValid()) {
		this->inputStatus = INPUT_STATUS_INVALID;
		return;
	}

	this->transformInputUppercase();

	if (!this->isInputMoveValid()) {
		this->inputStatus = INPUT_STATUS_INVALID;
		return;
	}

	this->inputStatus = INPUT_STATUS_OK;
}

bool ChessConclient::isInputExit() {
	if ((this->input == "q") || (this->input == "quit") || (this->input == "exit")) {
		return true;
	}

	return false;
}

bool ChessConclient::isInputLengthValid() {
	if (this->input.length() == 4) {
		return true;
	}

	return false;
}

void ChessConclient::transformInputUppercase() {
	for (auto & c : this->input) c = toupper(c);
}

bool ChessConclient::isInputMoveValid() {
	char i1 = this->input[0];
	char j1 = this->input[1];
	char i2 = this->input[2];
	char j2 = this->input[3];

	if (((i1 >= 'A') && (i1 < 'H')) &&
		((j1 >= '0') && (j1 < '8')) &&
		((i2 >= 'A') && (i2 < 'H')) &&
		((j2 >= '0') && (j2 < '8'))) {
		return true;
	}

	return false;
}
