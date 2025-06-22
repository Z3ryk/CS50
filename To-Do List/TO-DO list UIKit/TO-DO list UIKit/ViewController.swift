import UIKit

// 1
// перенести все, что связано с view, в отдельный класс - наследник UIView - ToDoListView +
// найти информацию, как в контроллере подставить свой кастомный класс в качестве основной вью +
// показ алерта должен пока остаться в контроллере ()

// 2
// вынести работу с UITableViewDataSource и UITableViewDelegate в отдельный класс - наследник NSObject - TableViewManager
// у него же внутри должны быть данные для отображения
// использовать этот класс в качестве delegate и dataSource для таблицы в отдельном классе вью

// 3
// ООП в Swift

// 4
// управление памятью в Swift

class ViewController: UIViewController {
    
    private lazy var toDoListView = ToDoListView(viewController: self)
    
    init() {
        super.init(nibName: nil, bundle: nil)
    }
    
    @available(*, unavailable)
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    override func loadView() {
        view = toDoListView
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        // some logic
    }
}

