#include "depixelizing.h"
Depixelizing::Depixelizing() :
    m_scale(20)
{
}
Depixelizing::~Depixelizing()
{
}
void Depixelizing::depixelize(const cv::Mat& image, float scaleFactor, std::string outname)
{
    //initialization
    m_width = image.cols;
    m_height = image.rows;
    m_image = image.clone();
    m_scale = scaleFactor;
    m_outname = outname;
    //depixelizing
    buildSimilarityGraph();
    showSimilarityGraph();
    deleteFullyConnectedBlocks();
    showSimilarityGraph();
    resolveHeuristics();
    showSimilarityGraph();
    buildCells();
    showCellGraph();
    combineCellsDiagonals();
    showCellGraph();
    remove2ValenceNodes();
    showCellGraph();
    reconstructPixelsToCells();
    showCellImage();
    combineCells();
    showCellGraph();
    findAllCurves();
    showCurves();
}
