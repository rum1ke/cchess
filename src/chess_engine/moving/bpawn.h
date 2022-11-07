bool ChessEngine::isCanMoveBPawn() {
	if (this->isPieceEquals(1, NOPIECE) && (this->i1 == this->i2)) {
		if (this->j1 - 1 == this->j2) {
			return true;
		}
		if ((this->j1 - 2 == this->j2) && (this->j1 == 6)) {
			return true;
		}
	}
	if (!(this->isPieceEquals(7, NOPIECE, BPAWN, BKNIGHT, BBISHOP, BROOK, BQUEEN, BKING)) && (this->j1 - 1 == this->j2)) {
		if (this->i1 + 1 == this->i2) {
			return true;
		}
		if (this->i1 - 1 == this->i2) {
			return true;
		}
	}
	return false;
}
