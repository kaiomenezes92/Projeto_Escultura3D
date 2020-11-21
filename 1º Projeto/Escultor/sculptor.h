#ifndef SCULPTOR_H
#define SCULPTOR_H

/**
 * @brief A estrura Voxel atribuirá cor (r, g b), transparência (a) e representação na saída (isOn).
 */
struct Voxel {
    /**
     * @brief r armazena a cor vermelha.
     */
    float r; // Colors
    /**
     * @brief g armazena a cor verde.
     */
    float g; // Colors
    /**
     * @brief b armazena a cor azul.
     */
    float b; // Colors
    /**
     * @brief a armazena a transparência.
     */
    float a;// Transparency
    /**
     * @brief inOn armazena a representação na saída.
     */
    bool isOn; // Included or not
};


/**
 * @brief A classe Sculptor cria várias funções, que farão a representação das esculturas.
 *
 * @details Será criado uma matriz 3D e serão atribuídas as dimensões e cores atuais.
 */
class Sculptor {
protected:
    /**
     * @brief v armazena a matriz 3D.
     */
    Voxel ***v;
    // 3D matrix
    /**
     * @brief nx armazena a dimensão em x.
     */
    int nx; // Dimensions
    /**
     * @brief ny armazena a dimensão em y.
     */
    int ny; // Dimensions
    /**
     * @brief nz armazena a dimensão em z.
     */
    int nz; // Dimensions
    /**
     * @brief r armazena a cor vermelha atual.
     */
    float r; // Current drawing color
    /**
     * @brief g armazena a cor verde atual.
     */
    float g; // Current drawing color
    /**
     * @brief b armazena a cor azul atual.
     */
    float b; // Current drawing color
    /**
     * @brief a armazena a transparência atual.
     */
    float a;
public:
    /**
     * @brief Sculptor é o construtor da classe.
     * @param _nx armazena a dimensão atual em x.
     * @param _ny armazena a dimensão atual em y.
     * @param _nz armazena a dimensão atual em z.
     */
    Sculptor(int _nx, int _ny, int _nz);
    ~Sculptor(); // desconstrutor
    /**
     * @brief setColor atribui a cor atual do desenho.
     * @param _r armazena a cor vermelha atual.
     * @param _g armazena a cor verde atual.
     * @param _b armazena a cor azul atual
     * @param alpha armazena a transparência.
     */
    void setColor(float _r, float _g, float _b, float alpha);
    /**
     * @brief putVoxel atribui um voxel na posição (x, y, z) (fazendo isOn = true) e atribui ao mesmo a cor atual de desenho.
     * @param x armazena a posição x.
     * @param y armazena a posição y.
     * @param z armazena a posição z.
     */
    void putVoxel(int x, int y, int z);
    /**
     * @brief cutVoxel desativa o voxel na posição (x, y, z) (fazendo isOn = false).
     * @param x armazena a posição x.
     * @param y armazena a posição y.
     * @param z armazena a posição z.
     */
    void cutVoxel(int x, int y, int z);
    /**
     * @brief putBox ativa todos os voxels no intervalo x∈[x0,x1], y∈[y0,y1], z∈[z0,z1] e atribui aos mesmos a cor atual de desenho.
     * @param x0 armazena o x0 inicial.
     * @param x1 armazena o x1 final.
     * @param y0 armazena o y0 inicial.
     * @param y1 armazena o y1 final.
     * @param z0 armazena o z0 inicial.
     * @param z1 armazena o z1 final.
     */
    void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
    /**
     * @brief cutBox desativa todos os voxels no intervalo x∈[x0,x1], y∈[y0,y1], z∈[z0,z1] e atribui aos mesmos a cor atual de desenho.
     * @param x0 armazena o x0 inicial.
     * @param x1 armazena o x1 final.
     * @param y0 armazena o y0 inicial.
     * @param y1 armazena o y1 final.
     * @param z0 armazena o z0 inicial.
     * @param z1 armazena o z1 final.
     */
    void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
    /**
     * @brief putSphere ativa todos os voxels que satisfazem à equação da esfera e atribui aos mesmos a cor atual de desenho (r,g,b,a).
     * @param xcenter armazena o x do centro.
     * @param ycenter armazena o y do centro.
     * @param zcenter armazena o z do centro.
     * @param radius armazena o raio.
     */
    void putSphere(int xcenter, int ycenter, int zcenter, int radius);
    /**
     * @brief cutSphere desativa todos os voxels que satisfazem à equação da esfera.
     * @param xcenter armazena o x do centro.
     * @param ycenter armazena o y do centro.
     * @param zcenter armazena o z do centro.
     * @param radius armazena o raio.
     */
    void cutSphere(int xcenter, int ycenter, int zcenter, int radius);
    /**
     * @brief putEllipsoid ativa todos os voxels que satisfazem à equação do elipsóide e atribui aos mesmos a cor atual de desenho.
     * @param xcenter armazena o x do centro.
     * @param ycenter armazena o y do centro.
     * @param zcenter armazena o z do centro.
     * @param rx armazena o semi eixo x.
     * @param ry armazena o semi eixo y.
     * @param rz armazena o semi eixo z.
     */
    void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    /**
     * @brief cutEllipsoid desativa todos os voxels que satisfazem à equação do elipsóide.
     * @param xcenter armazena o x do centro.
     * @param ycenter armazena o y do centro.
     * @param zcenter armazena o z do centro.
     * @param rx armazena o semi eixo x.
     * @param ry armazena o semi eixo y.
     * @param rz armazena o semi eixo z.
     */
    void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    /**
     * @brief writeOFF grava a escultura no formato OFF no arquivo filename.
     * @param filename armazena o nome do arquivo (exemplo.off).
     */
    void writeOFF(char* filename);
};

#endif // SCULPTOR_H
