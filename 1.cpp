class GraphicElement {
public:
    virtual void draw() = 0; // 绘制图元
    virtual void move(int x, int y) = 0; // 平移图元
    virtual void rotate(int angle) = 0; // 旋转图元
    virtual void scale(float ratio) = 0; // 缩放图元
    virtual void delete() = 0; // 删除图元
};

class Point : public GraphicElement {
private:
    int x, y;
public:
    virtual void draw() override;
    virtual void move(int x, int y) override;
    virtual void rotate(int angle) override;
    virtual void scale(float ratio) override;
    virtual void delete() override;
};

class Line : public GraphicElement {
private:
    Point start, end;
public:
    virtual void draw() override;
    virtual void move(int x, int y) override;
    virtual void rotate(int angle) override;
    virtual void scale(float ratio) override;
    virtual void delete() override;
};

class Polygon : public GraphicElement {
private:
    vector<Point> vertices;
public:
    virtual void draw() override;
    virtual void move(int x, int y) override;
    virtual void rotate(int angle) override;
    virtual void scale(float ratio) override;
    virtual void delete() override;
};

class Rectangle : public GraphicElement {
private:
    Point topLeft;
    float width, height;
public:
    virtual void draw() override;
    virtual void move(int x, int y) override;
    virtual void rotate(int angle) override;
    virtual void scale(float ratio) override;
    virtual void delete() override;
};

class Circle : public GraphicElement {
private:
    Point center;
    float radius;
public:
    virtual void draw() override;
    virtual void move(int x, int y) override;
    virtual void rotate(int angle) override;
    virtual void scale(float ratio) override;
    virtual void delete() override;
};

class Sector : public GraphicElement {
private:
    Circle circle;
    Point start;
    int angle;
public:
    virtual void draw() override;
    virtual void move(int x, int y) override;
    virtual void rotate(int angle) override;
    virtual void scale(float ratio) override;
    virtual void delete() override;
};

class Text : public GraphicElement {
private:
    string content;
    Point position;
    string font;
    int size;
public:
    virtual void draw() override;
    virtual void move(int x, int y) override;
    virtual void rotate(int angle) override;
    virtual void scale(float ratio) override;
    virtual void delete() override;
};

class Bitmap : public GraphicElement {
private:
    string filename;
    Point position;
    float width, height;
public:
    virtual void draw() override;
    virtual void move(int x, int y) override;
    virtual void rotate(int angle) override;
    virtual void scale(float ratio) override;
    virtual void delete() override;
};

enum BorderStyle { SOLID, DASHED, DOTTED };

class GraphicData {
private:
    vector<GraphicElement*> elements;
public:
    void addElement(GraphicElement* element);
    void removeElement(GraphicElement* element);
    void clear();
    void importShapeFile(string filename);
    void exportToFile(string filename);
    void exportToDatabase();
    void translateWindow(int x, int y);
    void zoomWindow(float ratio);
    void resetWindow();
    void analysisConvexHull();
    void analysisBuffer();
    void analysisOverlap();
    void analysisDelaunay();
    void analysisVoronoi();
    void statistics();
};

class Border {
private:
    BorderStyle style;
    int width;
    Color color;
public:
    void setStyle(BorderStyle style);
    void setWidth(int width);
    void setColor(Color color);
};

class Fill {
private:
    Color color;
    FillStyle style;
public:
    void setColor(Color color);
    void setStyle(FillStyle style);
};
class Color {
private:
    int r, g, b;
public:
    void setRGB(int r, int g, int b)
};

enum FillStyle {
    SOLID, HATCHED, GRADIENT
};

class HatchPattern {
private:
    int angle;
    float spacing;
public:
    void setAngle(int angle);
    void setSpacing(float spacing);
};

class Gradient {
private:
    Color start, end;
public:
    void setColor(Color start, Color end);
};

class Command {
public:
    virtual void execute() = 0;
    virtual void unExecute() = 0;
};

class GraphicEditor {
private:
    GraphicData data;
    stack<Command> history;
public:
    void createPoint();
    void createLine();
    void createPolygon();
    void createRectangle();
    void createCircle();
    void createSector();
    void createText();
    void createBitmap();
    void adjustElement();
    void translateElement();
    void rotateElement();
    void scaleElement();
    void deleteElement();
    void undo();
    void redo();
};

class ConvexHullAnalysisCommand : public Command {
public:
    virtual void execute() override;
    virtual void unExecute() override;
};

class BufferAnalysisCommand : public Command {
public:
    virtual void execute() override;
    virtual void unExecute() override;
};

class OverlapAnalysisCommand : public Command {
public:
    virtual void execute() override;
    virtual void unExecute() override;
};

class DelaunayAnalysisCommand : public Command {
public:
    virtual void execute() override;
    virtual void unExecute() override;
};

class VoronoiAnalysisCommand : public Command {
public:
    virtual void execute() override;
    virtual void unExecute() override;
};

class StatisticsAnalysisCommand : public Command {
public:
    virtual void execute() override;
    virtual void unExecute() override;
};
class ConvexHullAnalysisCommand : public Command {
public:
    virtual void execute() override;
    virtual void unExecute() override;
};

class BufferAnalysisCommand : public Command {
public:
    virtual void execute() override;
    virtual void unExecute() override;
};

class OverlapAnalysisCommand : public Command {
public:
    virtual void execute() override;
    virtual void unExecute() override;
};

class DelaunayAnalysisCommand : public Command {
public:
    virtual void execute() override;
    virtual void unExecute() override;
};

class VoronoiAnalysisCommand : public Command {
public:
    virtual void execute() override;
    virtual void unExecute() override;
};

class StatisticsAnalysisCommand : public Command {
public:
    virtual void execute() override;
    virtual void unExecute() override;
};

class ConvexHullAnalysis {
public:
    void execute();
};

class BufferAnalysis {
public:
    void execute();
};

class OverlapAnalysis {
public:
    void execute();
};

class DelaunayAnalysis {
public:
    void execute();
};

class VoronoiAnalysis {
public:
    void execute();
};

class StatisticsAnalysis {
public:
    void execute();
};
class ShapeFile {
private:
    string filename;
public:
    ShapeFile(string filename);
    ~ShapeFile();
    void readHeader();
    void readShape();
};

class ShapeFileImporter {
private:
    GraphicData* data;
    ShapeFile shapeFile;
public:
    ShapeFileImporter(GraphicData* data, string filename);
    void import();
};

class TextFileExporter {
private:
    GraphicData* data;
public:
    TextFileExporter(GraphicData* data);
    void exportToFile(string filename);
};

class BinaryFileExporter {
private:
    GraphicData* data;
public:
    BinaryFileExporter(GraphicData* data);
    void exportToFile(string filename);
};

class DatabaseExporter {
private:
    GraphicData* data;
public:
    DatabaseExporter(GraphicData* data);
    void exportToDatabase();
};


