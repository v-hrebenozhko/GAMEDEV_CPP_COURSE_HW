#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <fstream>
#include <iostream>

class SaveManager
{
public:
	void loadSave(const std::string saveFile);
	void save(const std::string saveFile, std::vector<std::string> saveData);
	const std::vector<std::string>& getSaveData() const {return m_save; }
	unsigned int getHighScore() const { return m_highScore; }
private:
	unsigned int m_highScore;
	std::vector<std::string> m_save;

};