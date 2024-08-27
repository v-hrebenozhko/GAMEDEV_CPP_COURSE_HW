#include "SaveManager.h"

void SaveManager::loadSave(const std::string saveFile)
{
	std::ifstream file;
	file.open(saveFile, std::ios::in);
	if (!file)
	{
		std::cout << "File not found!\n";
	}
	else
	{
		std::string line;
		while (std::getline(file, line))
		{
			std::istringstream stream(line);
			std::string str;
			std::getline(stream, str, ';');
			if (!str.empty())
			{
				m_save.push_back(str);
			}
		}
	}
	file.close();
	m_highScore = std::stoi(m_save[0]);
}
void SaveManager::save(const std::string saveFile,std::vector<std::string> saveData)
{
	std::ofstream file;
	file.open(saveFile, std::ios::out);
	if (!file)
	{
		std::cout << "File not found!\n";
	}
	else
	{
		std::string line;
		for (const std::string& line : saveData) {
			file << line;
		}
	}
	file.close();
}

const bool SaveManager::getIsSaveValid() const
{
	return m_save.size() > 1;
}
