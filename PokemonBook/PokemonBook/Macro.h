#pragma once

// �֐���`
#define RELEASE(x) if((x) != nullptr){ delete (x); (x) = nullptr; }

// �萔��`
#define WIND_H 640
#define WIND_W 1600
#define GRAPH_SIZE 32