#include "ChessNotation.hpp"
#include <iostream>
#include <fstream>
ChessNotation::ChessNotation()
{
}
bool hasExtension(const std::string& filename, const std::string& ext) {
	if (filename.length() >= ext.length()) {
		return filename.compare(filename.length() - ext.length(),
			ext.length(), ext) == 0;
	}
	return false;
}
bool ChessNotation::LoadFromFile(const char* filePath)
{
	m_chessBoard.SetBoardToStartState();
	if (hasExtension(filePath, ".pgn"))
	{
		return ParsePGN(filePath);
	}

	return false;
}
bool startsWithNumberDot(const std::wstring& s) {
	int i = 0;

	// must start with at least one digit
	while ( i < s.size())
	{
		
		bool bDigit = false;
		if (L'0' <= s[i] && s[i] <= L'9')
		{
			bDigit = true;
		}
		bool bSpace = s[i] == L' '; 
		if (bDigit || bSpace)
		{
			i++;
		}
		else
		{
			break;
		}
	}

	// check if there was at least one digit and next char is '.'
	bool bResult = (i > 0 && i < s.size() && s[i] == L'.');
	return bResult;
}

ChessMove_T ChessNotation::ParseMoveAct(const std::wstring& moveActStr)
{
	std::wstring CHESS_MAN_NAMES[] = { L"车",L"马",L"象",L"士",L"将",L"帅",L"炮",L"兵" };
	ChessMan_T  CHESS_MAN_TYPES[] = { ChessMan_T::ROOK_MAN,
									  ChessMan_T::KNIGHT_MAN,
									  ChessMan_T::BISHOP_MAN,
									  ChessMan_T::QUEEN_MAN,
									  ChessMan_T::KING_MAN,
									  ChessMan_T::KING_MAN,
									  ChessMan_T::CANNON_MAN,
									  ChessMan_T::PAWN_MAN };
	std::size_t LENGTH = sizeof(CHESS_MAN_NAMES) / sizeof(CHESS_MAN_NAMES[0]);
	ChessMove_T result;
	return result;
}

ChessMove_T ChessNotation::ParseMoveAct(const NotationMoveAct_T& notaMove)
{
	ChessMove_T chessMove;
	auto allPostion = m_chessBoard.GetChessGrids(notaMove.m_chessMan);
	int maxX = m_chessBoard.GetMaxX();
	int maxY = m_chessBoard.GetMaxY();
	if (notaMove.m_chessMan._color == ChessColor_T::RED_SIDE)
	{
		//ROOK
		if (notaMove.m_chessMan._manType == ChessMan_T::ROOK_MAN)
		{
			for (const auto& pos : allPostion)
			{

				if ((maxX - notaMove.m_fromNumber) == pos._gridX)
				{
					chessMove._fromGrid = pos;
					chessMove._chessMan = notaMove.m_chessMan;
					if (notaMove.m_moveDirection == MoveDirection_T::FORWARD_DIRECTION)
					{
						chessMove._toGrid._gridX = pos._gridX;
						chessMove._toGrid._gridY = pos._gridY - notaMove.m_toNumber;
						break;
					}
					else if (notaMove.m_moveDirection == MoveDirection_T::BACK_DIRECTION)
					{
						chessMove._toGrid._gridX = pos._gridX;
						chessMove._toGrid._gridY = pos._gridY + notaMove.m_toNumber;
						break;
					}
					else if (notaMove.m_moveDirection == MoveDirection_T::HORIZON_DIRECTION)
					{
						chessMove._toGrid._gridX = maxX - notaMove.m_toNumber;
						chessMove._toGrid._gridY = pos._gridY;
						break;
					}
				}
			}
		}

		//KNIGHT
		if (notaMove.m_chessMan._manType == ChessMan_T::KNIGHT_MAN)
		{
			for (const auto& pos : allPostion)
			{
			}
		}

		//BISHOP
		if (notaMove.m_chessMan._manType == ChessMan_T::BISHOP_MAN)
		{

		}

		//QUEEN
		if (notaMove.m_chessMan._manType == ChessMan_T::QUEEN_MAN)
		{

		}

		//KING
		if (notaMove.m_chessMan._manType == ChessMan_T::KING_MAN)
		{

		}

		//CANNON
		if (notaMove.m_chessMan._manType == ChessMan_T::CANNON_MAN)
		{

		}

		//PAWN
		if (notaMove.m_chessMan._manType == ChessMan_T::PAWN_MAN)
		{

		}
	}
	return chessMove;
}
NotationMoveAct_T ChessNotation::ParseNotationMoveAct(const std::wstring& moveActStr,const ChessColor_T& color)
{
	NotationMoveAct_T result;
	result.m_chessMan._color = color;
	if (moveActStr.length() == 4)
	{
		int index = 0;
		std::wstring parseStr;
		if (index < 4)
		{
			parseStr = moveActStr[index];
			auto pos = ParsePosition(parseStr);
			if (pos != NotationPosition_T::NONE_POSITION)
			{
				result.m_pos = pos;
				index++;
			}
		}
		if (index < 4)
		{
			parseStr = moveActStr[index];
			auto manType = WStringToChessMan(parseStr);
			if (manType != ChessMan_T::NONE_MAN)
			{
				result.m_chessMan._manType = manType;
				index++;
			}
		}
		if (index < 4)
		{
			parseStr = moveActStr[index];
			auto fromNunber = WStringToNumber(parseStr);
			if (fromNunber != -1)
			{
				result.m_fromNumber = fromNunber;
				index++;
			}
		}
		if (index < 4)
		{
			parseStr = moveActStr[index];
			auto direct = ParseDirection(parseStr);
			if (direct != MoveDirection_T::NONE_DIRECTION)
			{
				result.m_moveDirection = direct;
				index++;
			}
		}
		if (index < 4)
		{
			parseStr = moveActStr[index];
			auto toNumber = WStringToNumber(parseStr);
			if (toNumber != -1)
			{
				result.m_toNumber = toNumber;
				index++;
			}
		}
	}
	return result;
}

ChessMove_T ChessNotation::ParseNotationMoveActToChessMove(const NotationMoveAct_T& notationMoveAct)
{
	ChessMove_T result;
	auto allPostion = m_chessBoard.GetChessGrids(notationMoveAct.m_chessMan);
	for (auto& pos : allPostion)
	{
		if (notationMoveAct.m_fromNumber == pos._gridX + 1)
		{
			result._chessMan = notationMoveAct.m_chessMan;
			result._fromGrid = pos;
			if (notationMoveAct.m_moveDirection == MoveDirection_T::FORWARD_DIRECTION)
			{
				result._toGrid._gridX = pos._gridX;
				result._toGrid._gridY = pos._gridY - notationMoveAct.m_toNumber;
				break;
			}
			else if (notationMoveAct.m_moveDirection == MoveDirection_T::BACK_DIRECTION)
			{
				result._toGrid._gridX = pos._gridX;
				result._toGrid._gridY = pos._gridY + notationMoveAct.m_toNumber;
				break;
			}
			else if (notationMoveAct.m_moveDirection == MoveDirection_T::HORIZON_DIRECTION)
			{
				result._toGrid._gridX = notationMoveAct.m_toNumber;
				result._toGrid._gridY = pos._gridY; 
				break;
			}
		}
	}
	return result;
}

ChessMoveNotation_T ChessNotation::ParseMoveNotation(const std::wstring& moveNotation)
{
	ChessMoveNotation_T result;
	result.m_strRoundMoveNotation = moveNotation;

	//Point
	int pointIndex = moveNotation.find(L". ");
	if (pointIndex != std::wstring::npos)
	{
		pointIndex += 2;//skip ". "
		int spaceIndex = moveNotation.find(L' ', pointIndex);
		if (spaceIndex != std::wstring::npos)
		{
			std::wstring movePart = moveNotation.substr(pointIndex, spaceIndex - pointIndex);
			std::wstring movePart2 = moveNotation.substr(spaceIndex+1, moveNotation.length() - spaceIndex);
			result.m_redMove.m_strMoveNotation = movePart;
			result.m_blackMove.m_strMoveNotation = movePart2;
			std::wcout << "Move Part 1: " << movePart << std::endl;
			std::wcout << "Move Part 2: " << movePart2 << std::endl;	
		}
	}
	result.m_redMove.m_notationMoveAct = ParseNotationMoveAct(result.m_redMove.m_strMoveNotation,ChessColor_T::RED_SIDE);
	result.m_blackMove.m_notationMoveAct = ParseNotationMoveAct(result.m_blackMove.m_strMoveNotation, ChessColor_T::BLACK_SIDE);
	result.m_redMove.m_chessBoardMoveAct = ParseNotationMoveActToChessMove(result.m_redMove.m_notationMoveAct);
	result.m_blackMove.m_chessBoardMoveAct = ParseNotationMoveActToChessMove(result.m_blackMove.m_notationMoveAct);
	return result;
}

int ChessNotation::WStringToNumber(const std::wstring w) const
{
	std::wstring ChineseNumber[] = { L"零",L"一",L"二",L"三",L"四",L"五",L"六",L"七",L"八",L"九" };
	std::size_t CHINESE_NUMBER_LENGTH = sizeof(ChineseNumber) / sizeof(ChineseNumber[0]);

	for(int i = 0; i < CHINESE_NUMBER_LENGTH; i++)
	{
		if (w == ChineseNumber[i])
		{
			return i;
		}
	}

	std::wstring W_NUMBER[] = { L"０",L"１",L"２",L"３",L"４",L"５",L"６",L"７",L"８",L"９" };
	std::size_t W_NUMBER_LENGTH = sizeof(W_NUMBER) / sizeof(W_NUMBER[0]);

	for (size_t i = 0; i < W_NUMBER_LENGTH; i++)
	{
		if (w == W_NUMBER[i])
		{
			return i;
		}
	}
	
	return -1;
}

ChessMan_T ChessNotation::WStringToChessMan(const std::wstring& w) const
{
	std::wstring CHESS_MAN_NAMES[] = { L"车",L"马",L"象",L"相",L"士",L"将",L"帅",L"炮",L"兵",L"卒" };
	ChessMan_T  CHESS_MAN_TYPES[] = { ChessMan_T::ROOK_MAN,
									  ChessMan_T::KNIGHT_MAN,
									  ChessMan_T::BISHOP_MAN,
									  ChessMan_T::BISHOP_MAN,
									  ChessMan_T::QUEEN_MAN,
									  ChessMan_T::KING_MAN,
									  ChessMan_T::KING_MAN,
									  ChessMan_T::CANNON_MAN,
									  ChessMan_T::PAWN_MAN,
									  ChessMan_T::PAWN_MAN };
	std::size_t LENGTH = sizeof(CHESS_MAN_NAMES) / sizeof(CHESS_MAN_NAMES[0]);
	for (int i = 0; i < LENGTH; i++)
	{
		if (w == CHESS_MAN_NAMES[i])
		{
			return CHESS_MAN_TYPES[i];
		}
	}
	return ChessMan_T::NONE_MAN;
}

NotationPosition_T ChessNotation::ParsePosition(const std::wstring& w) const
{
	NotationPosition_T pos = NotationPosition_T::NONE_POSITION;
	std::wstring CHESS_MAN_POSITION[] = { L"前",L"中",L"后" };
	NotationPosition_T  POSITION_TYPES[] = { NotationPosition_T::FRONT_POSITION,
		                                     NotationPosition_T::MIDDLE_POSITION,
	                                         NotationPosition_T::BACK_POSITION};
	std::size_t LENGTH = sizeof(CHESS_MAN_POSITION) / sizeof(CHESS_MAN_POSITION[0]);
	for (int i = 0; i < LENGTH; i++)
	{
		if(w==CHESS_MAN_POSITION[i])
		{
			pos = POSITION_TYPES[i];
			break;
		}
	}
	return pos;
}

MoveDirection_T ChessNotation::ParseDirection(const std::wstring& w) const
{
	MoveDirection_T direction = MoveDirection_T::NONE_DIRECTION;
	const std::wstring DIRECTION_CHAR[] = { L"进",L"退",L"平" };
	const MoveDirection_T DIRECTION_TYPE[] = { MoveDirection_T::FORWARD_DIRECTION,MoveDirection_T::BACK_DIRECTION,MoveDirection_T::HORIZON_DIRECTION };
	std::size_t LENGTH = sizeof(DIRECTION_CHAR) / sizeof(DIRECTION_CHAR[0]);
	for (int i = 0; i < LENGTH; i++)
	{
		if (w == DIRECTION_CHAR[i])
		{
			direction = DIRECTION_TYPE[i];
			break;
		}
	}
	return direction;
}

bool ChessNotation::ParsePGN(const char* filePath)
{
	auto lines = TextFileReader::ReadAllLines(filePath);
	int lineNum = 1;
	for(const auto& line:lines)
	{
		std::wcout << "Line " << lineNum << ": " << line << std::endl;
		if (line.find(L"Game") == 1)
		{
			m_pgnNotation.m_strGame = line;
		}
		if (line.find(L"Event") == 1)
		{
			m_pgnNotation.m_strEvent = line;
		}
		if (line.find(L"Round") == 1)
		{
			m_pgnNotation.m_strRound = line;
		}
		if (line.find(L"Date") == 1)
		{
			m_pgnNotation.m_strDate = line;
		}
		if (line.find(L"Site") == 1)
		{
			m_pgnNotation.m_strSite = line;
		}
		if (line.find(L"Red") == 1)
		{
			m_pgnNotation.m_strRed = line;
		}
		if (line.find(L"RedTeam") == 1)
		{
			m_pgnNotation.m_strRedTeam = line;
		}
		if (line.find(L"Black") == 1)
		{
			m_pgnNotation.m_strBlack = line;
		}
		if (line.find(L"BlackTeam") == 1)
		{
			m_pgnNotation.m_strBlackTeam = line;
		}
		if (line.find(L"Result") == 1)
		{
			m_pgnNotation.m_strResult = line;
		}
		if (line.find(L"ECCO") == 1)
		{
			m_pgnNotation.m_strECCO = line;
		}
		if (line.find(L"FEN") == 1)
		{
			m_pgnNotation.m_strFEN = line;
			
		}
		if (startsWithNumberDot(line))
		{
			ChessMoveNotation_T moveNotation = ParseMoveNotation(line);
			m_pgnNotation.m_strMoveVec.push_back(moveNotation);
		}
		lineNum++;
	}
	return true;
}

bool ChessNotation::SaveToFile(const char* filePath) const
{
	return false;
}

bool ChessNotation::OnPrevMove()
{
	return false;
}

bool ChessNotation::OnNextMove()
{
	return false;
}

void ChessNotation::PrintPGNNotation() const
{
	std::wcout << "------------------PGN Notation:----------------------" << std::endl;
	std::wcout << "Game: " << m_pgnNotation.m_strGame << std::endl;
	std::wcout << "Event: " << m_pgnNotation.m_strEvent << std::endl;
	std::wcout << "Round: " << m_pgnNotation.m_strRound << std::endl;
	std::wcout << "Date: " << m_pgnNotation.m_strDate << std::endl;
	std::wcout << "Site: " << m_pgnNotation.m_strSite << std::endl;
	std::wcout << "Red: " << m_pgnNotation.m_strRed << std::endl;
	std::wcout << "RedTeam: " << m_pgnNotation.m_strRedTeam << std::endl;
	std::wcout << "Black: " << m_pgnNotation.m_strBlack << std::endl;
	std::wcout << "BlackTeam: " << m_pgnNotation.m_strBlackTeam << std::endl;
	std::wcout << "Result: " << m_pgnNotation.m_strResult << std::endl;
	std::wcout << "ECCO: " << m_pgnNotation.m_strECCO << std::endl;
	std::wcout << "FEN: " << m_pgnNotation.m_strFEN << std::endl;
	std::wcout << "Comment: " << m_pgnNotation.m_strComment << std::endl;
	std::wcout << "---------------Moves:------------- " << std::endl;
	for (const auto& move : m_pgnNotation.m_strMoveVec)
	{
		std::wcout << "Action Begin : " << std::endl;
		std::wcout << move.m_strRoundMoveNotation << std::endl;
		{
			//RED
			std::wcout << "Red Move Notation: " << move.m_redMove.m_strMoveNotation << std::endl;
			std::wcout << " Red Notation: " << ToString(move.m_redMove.m_notationMoveAct).c_str() << std::endl;
			std::wcout << " MOVE: " << ToString(move.m_redMove.m_chessBoardMoveAct).c_str() << std::endl;
			//std::wcout << "  ("<<move.m_redMove.m_chessBoardMoveAct._fromGrid._gridX << "," << move.m_redMove.m_chessBoardMoveAct._fromGrid._gridY << ")---->(" << move.m_redMove.m_chessBoardMoveAct._toGrid._gridX << "," << move.m_redMove.m_chessBoardMoveAct._toGrid._gridY<<")" << std::endl;
			//Black
			std::wcout << "Black Move Notation: " << move.m_blackMove.m_strMoveNotation << std::endl;
			std::wcout << " Black Notation: " << ToString(move.m_blackMove.m_notationMoveAct).c_str() << std::endl;
			std::wcout << " MOVE: " << ToString(move.m_blackMove.m_chessBoardMoveAct).c_str() << std::endl;
			//std::wcout << "  (" << move.m_blackMove.m_chessBoardMoveAct._fromGrid._gridX << "," << move.m_blackMove.m_chessBoardMoveAct._fromGrid._gridY << ")---->(" << move.m_blackMove.m_chessBoardMoveAct._toGrid._gridX << "," << move.m_blackMove.m_chessBoardMoveAct._toGrid._gridY << ")" << std::endl;
		}
		std::wcout << "Action End: " << std::endl;
	}
	std::wcout << "------------------End of PGN Notation----------------------" << std::endl;
}

std::string ToString(const MoveDirection_T& direct)
{
	std::string strResult;
	switch (direct)
	{
	case MoveDirection_T::FORWARD_DIRECTION:
	{
		strResult = "FORWARD";
	}break;
	case MoveDirection_T::BACK_DIRECTION:
	{
		strResult = "BACK";
	}break;
	case MoveDirection_T::HORIZON_DIRECTION:
	{
		strResult = "HORIZON";
	}break;
	default:
	{
		strResult = "NONE";
	}break;
	}
	return strResult;
}

std::string ToString(const NotationMoveAct_T& moveAct)
{
	std::string strResult;
	strResult += ToString(moveAct.m_chessMan);
	strResult += " From: " + std::to_string(moveAct.m_fromNumber);
	strResult += " To: " + std::to_string(moveAct.m_toNumber);
	strResult += " Direction: " + ToString(moveAct.m_moveDirection);
	return strResult;
}