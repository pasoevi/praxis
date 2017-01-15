#include <gtk/gtk.h>
 
static void on_window_closed (GtkWidget *widget, gpointer data)
{
    gtk_main_quit ();
}
 
int main (int argc, char *argv[])
{
    GtkWidget *window, *label;
 
    /* Initialisieren */
    gtk_init (&argc, &argv);
    /* Fenster erzeugen */
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    /* "destroy"-Ereignis mit einer Funktion verknüpfen */
    g_signal_connect (window, "destroy", G_CALLBACK(on_window_closed), NULL);
    /* Textfeld erzeugen */
    label = gtk_label_new ("Hallo, Welt!");
    /* Textfeld dem Fenster hinzufügen */
    gtk_container_add (GTK_CONTAINER(window), label);
    /* Alle erzeugten Widgets anzeigen lassen */
    gtk_widget_show (label);
    gtk_widget_show (window);
    /* Ereignisschleife */
    gtk_main ();
 
    return 0;
}
