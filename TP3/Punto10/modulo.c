#include <linux/init.h> /* Para usar la macro de __init y __exit */
#include <linux/module.h> /* Lib para modulos */
#include <linux/kernel.h> /* Para usar la macro KERN_INFO */

/*
10.Implemente un pequeño ejemplo de un módulo funcional en lenguaje C, indicando
los pasos necesarios para su creación. El módulo puede ser algo tan sencillo como
mostrar un mensaje al cargarlo y otro al descargarlo.
*/

static int __init mi_modulostart(void){
    printk(KERN_INFO "Hola mundo");
    return 0;
}

static void __exit mi_moduloexit(void){
    printk(KERN_INFO "Nos vemos mundo");
}

module_init(mi_modulostart);
module_exit(mi_moduloexit);

MODULE_LICENSE("lala");