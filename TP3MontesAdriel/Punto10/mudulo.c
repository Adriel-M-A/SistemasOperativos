

/*
10.Implemente un pequeño ejemplo de un módulo funcional en lenguaje C, indicando
los pasos necesarios para su creación. El módulo puede ser algo tan sencillo como
mostrar un mensaje al cargarlo y otro al descargarlo.
*/


int main(){
    
}

/* 
* Ejemplo de como crear un modulo
*/

/*
* 
*/

#include <linux/module.h> /* Lib para modulos */
#include <linux/kernel.h> /* Para usar la macro KERN_INFO */
#include <linux/init.h> /* Para usar la macro de inicio y fin */

static init __init mi_modulostart(void){

}

static void __exit mi_modulocleanup(void){
    printk(KERN_INFO "adios mundo desde mi macro")
}