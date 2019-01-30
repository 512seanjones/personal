import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.stage.Stage;
import javafx.scene.text.Text;
import javafx.scene.shape.Circle;
import javafx.scene.shape.Line;

public class Board extends Application {
    @Override
    public void start(Stage primaryStage) {

        Pane pane = new Pane();

        Line c1 = new Line(50, 50, 50, 650);
        c1.setStroke(Color.BLACK);
        c1.setStrokeWidth(5);
        pane.getChildren().add(new Text(100, 680, "1"));
        pane.getChildren().add(c1);

        Line c2 = new Line(150, 50, 150, 650);
        c2.setStroke(Color.BLACK);
        c2.setStrokeWidth(5);
        pane.getChildren().add(new Text(200, 680, "2"));
        pane.getChildren().add(c2);

        Line c3 = new Line(250, 50, 250, 650);
        c3.setStroke(Color.BLACK);
        c3.setStrokeWidth(5);
        pane.getChildren().add(new Text(300, 680, "3"));
        pane.getChildren().add(c3);

        Line c4 = new Line(350, 50, 350, 650);
        c4.setStroke(Color.BLACK);
        c4.setStrokeWidth(5);
        pane.getChildren().add(new Text(400, 680, "4"));
        pane.getChildren().add(c4);

        Line c5 = new Line(450, 50, 450, 650);
        c5.setStroke(Color.BLACK);
        c5.setStrokeWidth(5);
        pane.getChildren().add(new Text(500, 680, "5"));
        pane.getChildren().add(c5);

        Line c6 = new Line(550, 50, 550, 650);
        c6.setStroke(Color.BLACK);
        c6.setStrokeWidth(5);
        pane.getChildren().add(new Text(600, 680, "6"));
        pane.getChildren().add(c6);

        Line c7 = new Line(650, 50, 650, 650);
        c7.setStroke(Color.BLACK);
        c7.setStrokeWidth(5);
        pane.getChildren().add(new Text(700, 680, "7"));
        pane.getChildren().add(c7);

        Line c8 = new Line(750, 50, 750, 650);
        c8.setStroke(Color.BLACK);
        c8.setStrokeWidth(5);
        pane.getChildren().add(c8);

        Line r1 = new Line(50, 650, 750, 650);
        r1.setStroke(Color.BLACK);
        r1.setStrokeWidth(5);
        pane.getChildren().add(r1);

        Line r2 = new Line(50, 550, 750, 550);
        r2.setStroke(Color.BLACK);
        r2.setStrokeWidth(5);
        pane.getChildren().add(r2);

        Line r3 = new Line(50, 450, 750, 450);
        r3.setStroke(Color.BLACK);
        r3.setStrokeWidth(5);
        pane.getChildren().add(r3);

        Line r4 = new Line(50, 350, 750, 350);
        r4.setStroke(Color.BLACK);
        r4.setStrokeWidth(5);
        pane.getChildren().add(r4);

        Line r5 = new Line(50, 250, 750, 250);
        r5.setStroke(Color.BLACK);
        r5.setStrokeWidth(5);
        pane.getChildren().add(r5);

        Line r6 = new Line(50, 150, 750, 150);
        r6.setStroke(Color.BLACK);
        r6.setStrokeWidth(5);
        pane.getChildren().add(r6);

        Circle[] p = new Circle[42];
        for (int i = 0; i < 42; i++)
            p[i] = new Circle(0, 0, 0);

        addPiece(p, 5, 0, 'Y');
        pane.getChildren().add(p[35]);
        addPiece(p, 5, 1, 'R');
        pane.getChildren().add(p[36]);

        Scene scene = new Scene(pane, 800, 700);
        primaryStage.setTitle("Connect 4");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    public void addPiece(Circle[] p, int row, int col, char player){
        int x = 100 + 100 * col;
        int y = 100 + 100 * row;
        int num = row * 7 + col;
        p[num] = new Circle(x, y, 50);
        if (player == 'R')
            p[num].setFill(Color.RED);
        else
            p[num].setFill(Color.YELLOW);
    }
}
