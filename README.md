# Setup jupiter in virtial environment
```bash
python3 -m venv ds
. ds/bin/activate
pip install --upgrade pip
pip install jupyter pandas numpy matplotlib seaborn sodapy
jupyter nbextension enable --py --sys-prefix ipympl
pip install ipympl
jupyter notebook
```
