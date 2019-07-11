#include <stdbool.h>
#include <gtk/gtk.h>

static void create_app_menu(GtkApplication *app) {
  GMenuModel app_menu;

  // gtk_application_set_app_menu(app, &app_menu);

  // bool a = gtk_application_prefers_app_menu(app);
}

int count = 0;


// static void do_calculate(GtkWidget *calculate, gpointer data) {
//   int num1 = atoi((char *)gtk_entry_get_text(GTK_ENTRY(number1)));
//   int num2 = atoi((char *)gtk_entry_get_text(GTK_ENTRY(number2)));

//   char buffer[32];
//   snprintf(buffer, sizeof(buffer), "result: %d", num1 + num2);

//   gtk_label_set_text(GTK_LABEL(result), buffer);
// }

// static void count_button(GtkWidget *widget, gpointer ptr) {
//   char buffer[30];
//   count++;
//   sprintf(buffer, "Button pressed %d times", count);
//   gtk_button_set_label(GTK_BUTTON(ptr), buffer);
// }

static void activate (GtkApplication* app, gpointer data) {
  // window
  GtkWidget *window;
  window = gtk_application_window_new (app);
  gtk_window_set_title(GTK_WINDOW(window), "Tic Tac Toe");
  gtk_window_set_default_size(GTK_WINDOW(window), 600, 600);
  gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
  g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

  create_app_menu(app);
  // grid
  GtkWidget *grid;
  grid = gtk_grid_new();
  gtk_container_add(GTK_CONTAINER(window), grid);
  gtk_grid_set_column_spacing(GTK_GRID(grid), 5);
  gtk_grid_set_row_spacing(GTK_GRID(grid), 5);
  gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);

  // btn
  GtkWidget *north_west_button;
  north_west_button = gtk_button_new();
  // g_signal_connect(btn, "clicked", G_CALLBACK(count_button), btn);
  gtk_grid_attach(GTK_GRID(grid), GTK_WIDGET(north_west_button), 0, 0, 1, 40);

  GtkWidget *north_button;
  north_button = gtk_button_new();
  // g_signal_connect(btn2, "clicked", G_CALLBACK(count_button), btn2); 
  gtk_grid_attach(GTK_GRID(grid), GTK_WIDGET(north_button), 1, 0, 1, 40);

  GtkWidget *north_east_button;
  north_east_button = gtk_button_new();
  // g_signal_connect(btn3, "clicked", G_CALLBACK(count_button), btn3);
  gtk_grid_attach(GTK_GRID(grid), GTK_WIDGET(north_east_button), 2, 0, 1, 40);

  GtkWidget *east_button;
  east_button = gtk_button_new();
  gtk_grid_attach(GTK_GRID(grid), GTK_WIDGET(east_button), 0, 4, 1, 40);

  // init
  gtk_widget_show_all(window);
  gtk_main();

  return;
}

int main(int argc, char *argv[]) {
  GtkApplication *app;
  short int status;

  app = gtk_application_new("org.gtk.example", G_APPLICATION_FLAGS_NONE);
  g_signal_connect(app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}
