#pragma once

// 関数定義
#define RELEASE(x) if((x) != nullptr){ delete (x); (x) = nullptr; }

// 定数定義
#define WIND_H 640
#define WIND_W 1600
#define GRAPH_SIZE 32