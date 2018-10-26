# Docker Image

```sh
docker pull eosio/eos
./run.sh
alias cleos='docker exec -it eosio /opt/eosio/bin/cleos --url http://127.0.0.1:7777 --wallet-url http://127.0.0.1:5555'
```

# Toolchain

```sh
brew tap eosio/eosio
brew install eosio
brew tap eosio/eosio.cdt
brew install eosio.cdt
```

Now you should finish the first step of the introduction (see links).

# Demo

```sh
cd addressbook
./deploy.sh
```

# Links

- [https://developers.eos.io/eosio-home/docs/introduction](https://developers.eos.io/eosio-home/docs/introduction)
- [https://github.com/EOSIO/eosio.contracts](https://github.com/EOSIO/eosio.contracts)
