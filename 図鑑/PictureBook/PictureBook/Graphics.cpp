#include "Graphics.h"

std::vector<GS>Graphics::graph;

Graphics::Graphics()
{
	// ��`�����̉摜�n���h�����������m��
	graph.resize(PicData::GetDataNum());
}

Graphics::~Graphics()
{
	if (!graph.empty())// �z�񂪋󂶂�Ȃ�������
	{
		for (int i = 0, n = (unsigned)graph.size(); i < n; i++)
		{
			DeleteGraph(graph.at(i).graph);
			graph.at(i).graph = 0;
		}
		graph.erase(graph.begin(), graph.end());
	}
}

void Graphics::GraphLoad(const char* path)
{
	// �z��̐������ǂݍ��ݏ������s��
	for (int i = 0, n = (unsigned)graph.size(), _gr = 0; i < n; i++)
	{
		// �ǂ݂��ݐ�̃p�X�̎w��
		std::string filepath = path + std::to_string(i) + ".png";
		
		// �G���[�`�F�b�N
		_gr = LoadGraph(filepath.c_str());
		if (_gr != -1)
		{
			GS gs; 
			gs.graph = _gr;
			GetGraphSize(gs.graph, &gs.sizeX, &gs.sizeY);
			graph.at(i) = gs;
		}
		else
		{
			GS gs;
			gs.graph = 0;
			gs.sizeX = 0;
			gs.sizeY = 0;
			graph.at(i) = gs;
		}
	}
}

GS Graphics::GetGraph(const int pName)
{
	// �摜�n���h���̎擾
	return graph.at(pName);
}

const int Graphics::GetGraphNum()
{
	return (unsigned)graph.size();
}