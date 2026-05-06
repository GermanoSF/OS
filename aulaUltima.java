/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package os;

/**
 *
 * @author laboratorio
 */

public class Buffer {
private int conteudo;
private boolean disponivel = false;

public synchronized void set (int valor) { 
    while (disponivel) {
        try {
        wait(); // Espera até o buffer estar vazio
        } catch (InterruptedException e) { }
    }
conteudo = valor;
disponivel = true;
notifyAll(); // Notifica que o buffer agora está cheio
}
public synchronized int get() {
    while (!disponivel) {
    }
    try {
        wait(); // Espera até o buffer estar cheio
    } catch (InterruptedException e) {}
    disponivel = false;
    notifyAll(); // Notifica que o buffer agora está vazio
    return conteudo;
    }
}
