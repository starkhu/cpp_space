import torch
from torch.utils.data import Dataset, DataLoader

class RandomDataset(Dataset):
    def __init__(self, size, length):
        self.len = length
        data = torch.randn(length,size)
        self.data = torch.tril(data)
    def __getitem__(self, index):
        print("index is: ", index)
        return self.data[index]
    def __len__(self):
        return self.len
    def collate(self, x):
        print("x len is: ", len(x))
        for i in range(len(x)):
            x[i].sub_(1.0)
        return x

def create_or_get_dataloader(input_size, data_size, batch_size):
    dataset = RandomDataset(input_size, data_size)
    tril_loader = DataLoader(dataset= dataset,
                             batch_size=batch_size,
                             collate_fn = dataset.collate,
                             num_workers=0,
                             pin_memory=False,
                             drop_last=False,
                             shuffle=False
                             )
    return tril_loader


loader = create_or_get_dataloader(10, 10, 2)


for d in loader:
    print(d)
