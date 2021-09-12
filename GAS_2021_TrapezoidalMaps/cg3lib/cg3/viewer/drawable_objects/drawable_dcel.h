/*
 * This file is part of cg3lib: https://github.com/cg3hci/cg3lib
 * This Source Code Form is subject to the terms of the GNU GPL 3.0
 *
 * @author Alessandro Muntoni (muntoni.alessandro@gmail.com)
 * @author Andreas Scalas (andreasscalas@gmail.com)
 */

#ifndef CG3_DRAWABLE_DCEL_H
#define CG3_DRAWABLE_DCEL_H

#include <cg3/viewer/interfaces/drawable_mesh.h>
#include <cg3/utilities/utils.h>
#include <cg3/meshes/dcel/dcel.h>

namespace cg3 {

/**
 * @ingroup cg3viewer
 * @brief The DrawableDcel class allows to draw a Dcel in the Viewer.
 * In order to make visible any change made in the Dcel, you must execute the method DrawableDcel::update().
 *
 * @warning if you need performance, do not call update() inside a draw method; call it only when you made some modifications in the dcel.
 */
class DrawableDcel : public Dcel, public DrawableMesh
{
public:

    DrawableDcel();
	DrawableDcel(const char* filename);
	DrawableDcel(const std::string& filename);
    DrawableDcel(const Dcel &d);

    void clear();

    // Implementation of the
    // DrawableObject interface
    //
    void draw() const;
    Point3d sceneCenter() const;
    double sceneRadius() const;

    void update();

    void setFacesWireframe(bool b);
    void setFacesWireframeWidth(int w);
    void setFacesWireframeColor(float r, float g, float b);
    void setFlaggedEdgesWireframe(bool b, int flag = 1, int w = 4, cg3::Color color = cg3::BLACK);

    // SerializableObject interface
    void deserialize(std::ifstream& binaryFile);

    //Override Dcel
    bool loadFromDcelFile(const std::string &filename);
    // Mesh interface
    bool loadFromObj(const std::string &filename);
    bool loadFromPly(const std::string &filename);
    bool loadFromFile(const std::string &filename);

protected:

    void init();

    void renderPass(unsigned int nv, unsigned int nt, const double* coords, const int* triangles, const double* vertexNormals, const float* vertexColors, const double* triangleNormals, const float* triangleColors) const;

    enum {
        DRAW_FACES_WIREFRAME = 0b0100000000,
        DRAW_FLAGGED_EDGES = 0b1000000000
    };

    std::vector<double> vertexCoordinates; /** \~Italian @brief vettore di coordinate usate per la visualizzazione: per aggiornare utilizzare metodo update() */
    std::vector<int> triangles; /** \~Italian @brief vettore di triangoli (da considerare a triple di indici) usati per la visualizzazione: per aggiornare utilizzare il metodo update() */
    std::vector<double> vertexNormals; /** \~Italian @brief vettore di normali ai vertici usate per la visualizzazione: per aggiornare utilizzare il metodo update() */
    std::vector<float> vertexColors; /** \~Italian @brief vettore di colori associati ai vertici (da considerare come triple rgb float) usati per la visualizzazione: per aggiornare utilizzare il metodo update() */
    std::vector<double> triangleNormals; /** \~Italian @brief vettore di normali ai triangoli usate per la visualizzazione: per aggiornare utilizzare il metodo update() */
    std::vector<float> triangleColors; /** \~Italian @brief vettore di colori associati ai triangoli (da considerare come triple rgb float) usati per la visualizzazione: per aggiornare utilizzare il metodo update() */

    std::map<unsigned int, unsigned int> facesTrianglesMap; /** Maps the DcelFace to the first triangle associated to it */
    std::vector<unsigned int> trianglesFacesMap; /** \~Italian @brief vettore di mappatura triangoli->facce (ogni entrata ha posizione corrispondente a un terzo della posizione della tripla in tris e presenta l'identificativo di una faccia */
    std::vector<std::pair<unsigned int, unsigned int> > facesWireframe; /** \~Italian @brief vettore di coppie usate per renderizzare degli edge: per aggiornare utilizzare metodo update() */

    std::vector<cg3::Point3d> flaggedEdges;

    int facesWireframeWidth = 1;
    float facesWireframeColor[3];

    int flag = 1;
    int flaggedEdgesWireframeWidth = 5;
    cg3::Color flaggedEdgesColor = cg3::BLACK;
};

} //namespace cg3

#ifndef CG3_STATIC
#define CG3_DRAWABLE_DCEL_CPP "drawable_dcel.cpp"
#include CG3_DRAWABLE_DCEL_CPP
#undef CG3_DRAWABLE_DCEL_CPP
#endif //CG3_STATIC

#endif // CG3_DRAWABLE_DCEL_H
