#pragma once
class Stage
{
public:
	Stage();
	virtual ~Stage();

	void Init();
	void Update();
	void Draw();

	void LoadMapData(int mapData);
private:
	int m_stageMat[7][4];
	int m_handle;
};

